#include "mywidget.h"
#include "mypushbutton.h"
#include <QPushButton>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->setText("btn1");

    QPushButton *btn2 = new QPushButton("btn2", this);
    resize(600, 400);
    btn2->move(100, 100);
    btn2->resize(200, 200);

    // 设置窗口标题
    setWindowTitle("window");

    // 设置固定窗口大小
    setFixedSize(600, 400);

    MyPushButton *myBtn = new MyPushButton;
    myBtn->setText("自己的按钮");
    myBtn->move(400, 0);
    myBtn->setParent(this);

    // 信号和槽
    connect(myBtn, &QPushButton::clicked, this, &QWidget::close);
}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget析构函数";
}

