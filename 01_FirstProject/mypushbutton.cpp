#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{
    qDebug() << "MyPushButton构造函数";
}

MyPushButton::~MyPushButton()
{
    qDebug() << "MyPushButton析构函数";
}
