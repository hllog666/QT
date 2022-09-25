#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "简介");
    QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    QStringList hero1;
    hero1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    QTreeWidgetItem *l1 = new QTreeWidgetItem(hero1);
    liItem->addChild(l1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

