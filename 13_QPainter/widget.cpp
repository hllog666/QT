#include "widget.h"
#include "./ui_widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(QColor(255, 0, 0));
    pen.setWidth(3);
    pen.setStyle(Qt::DotLine);
    painter.setPen(pen);
    QBrush brush(Qt::green);
    brush.setStyle(Qt::Dense7Pattern);
    painter.setBrush(brush);
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
    painter.drawEllipse(QPoint(100, 100), 50, 50);
    painter.drawRect(QRect(20, 20, 50, 50));
    painter.drawText(QRect(10, 200, 100, 50), "goog good study, day day up");

    // 高级操作
    QPainter painter2(this);
    painter2.drawEllipse(QPoint(300, 300), 50, 50);
    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    painter2.drawEllipse(QPoint(300, 400), 50, 50);

    painter.drawRect(QRect(500, 200, 50, 50));
    painter2.translate(100, 0);
    // 保存状态
    painter2.save();
    painter.drawRect(QRect(500, 200, 50, 50));
    painter2.translate(100, 0);
    // 还原状态
    painter2.restore();
    painter.drawRect(QRect(500, 200, 50, 50));

    QPainter painter3(this);
    posX += 20;
    painter3.drawPixmap(posX, 300, QPixmap(":/image/01.png"));
}
