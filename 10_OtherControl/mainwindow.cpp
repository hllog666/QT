#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_scollArea, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_toolBox, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btn_tabWidget, &QPushButton::clicked, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");
}

MainWindow::~MainWindow()
{
    delete ui;
}

