#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon(":/image/01.png"));
    ui->actionopen->setIcon(QIcon(":/image/02.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

