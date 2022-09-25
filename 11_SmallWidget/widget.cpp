#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btn_get, &QPushButton::clicked, [=]() {
        qDebug() << ui->widget->getNum();
    });

    connect(ui->btn_set, &QPushButton::clicked, [=]() {
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

