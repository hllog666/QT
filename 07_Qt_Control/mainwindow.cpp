#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRadioButton>
#include <QDebug>
#include <QCheckBox>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rBtnMan->setChecked(true);
    connect(ui->rBtnWoman, &QRadioButton::clicked, [=]() {
        qDebug() << "女";
    });

    connect(ui->cBox, &QCheckBox::clicked, [=](int state) {
        qDebug() << state;
    });

    // QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    // ui->listWidget->addItem(item);
    // item->setTextAlignment(Qt::AlignCenter);

    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);
}

MainWindow::~MainWindow()
{
    delete ui;
}

