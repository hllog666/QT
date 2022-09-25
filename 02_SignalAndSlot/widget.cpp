#include "widget.h"
#include "./ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->zt = new Teacher;
    this->st = new Student;

    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: *studentSlot)(QString) = &Student::treat;

    // connect(zt, teacherSignal, st, studentSlot);

    classIsOver();

    QPushButton *btn = new QPushButton("下课", this);
    this->resize(600, 400);
    // connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);

    void(Teacher:: *teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: *studentSlot2)(void) = &Student::treat;
    connect(zt, teacherSignal2, st, studentSlot2);
    connect(btn, &QPushButton::clicked, zt, teacherSignal2);
    // 断开信号
    // disconnect(zt, teacherSignal2, st, studentSlot2);

    // 一个信号可以连接多个槽
    // 多个信号可以连接同一个槽
    // 信号的参数个数可以多于槽函数的参数个数

    [=]() {
        btn->setText("下课啦");
    }();

    QPushButton *btn2 = new QPushButton;
    btn2->setText("关闭");
    btn2->setParent(this);
    btn2->move(400, 0);
    connect(btn2, &QPushButton::clicked, this, [this](){
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver()
{
    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}
