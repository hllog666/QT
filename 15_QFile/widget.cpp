#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QFile>
// #include <QTextCodec>
#include <QFileInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "E:\\download");
        ui->lineEdit->setText(path);
        // QT6中移除了QTextCodec
        // QTextCodec *codec = QTextCodec::codecForName("gbk");
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        // ui->textEdit->setText(codec->toUnicode(array));
        ui->textEdit->setText(array);
        file.close();
        // 写文件
//        file.open(QIODevice::Append);
//        file.write("哈哈哈哈哈");
//        file.close();

        QFileInfo info(path);
        qDebug() << info.size() << info.suffix() << info.fileName();
        qDebug() << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
    });
}

Widget::~Widget()
{
    delete ui;
}

