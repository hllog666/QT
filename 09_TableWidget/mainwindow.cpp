#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");
    ui->tableWidget->setRowCount(5);
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));
    QStringList namelist;
    namelist << "亚瑟" << "赵云" << "张飞" << "关羽" << "花木兰";
    QList<QString> sexList;
    sexList << "男" << "男" << "男" << "男"  << "女";

    for (int i = 0; i < 5; i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i + 18)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

