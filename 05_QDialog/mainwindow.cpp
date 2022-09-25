#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew, &QAction::triggered, [=]() {
        // 模态对话框
        QDialog dlg(this);
        dlg.resize(200, 100);
        dlg.exec();
        qDebug() << "模态对话框弹出了";
    });

    connect(ui->actionopen, &QAction::triggered, [=]() {
        // 非模态对话框
        // 在堆中创建，避免一闪而过
        QDialog *dlg = new QDialog(this);
        dlg->resize(200, 100);
        dlg->show();
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        qDebug() << "非模态对话框弹出了";
    });

    connect(ui->actionclose, &QAction::triggered, [=]() {
        // QMessageBox::critical(this, "critical", "错误");
        // QMessageBox::information(this, "info", "信息");
        /* if(QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        {
            qDebug() << "保存";
        }
        else
        {
            qDebug() << "取消";
        } */
        QMessageBox::warning(this, "warning", "警告");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

