#include "widget.h"
#include "./ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pix(300, 300);
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(Qt::green);
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    pix.save("E:/code/QT/13_QPainter/image/03.png");

    // 可以对像素进行修改
//    QImage image(300, 300, QImage::Format_RGB32);
//    image.fill(Qt::white);
//    QPainter painter(&image);
//    painter.setPen(Qt::green);
//    painter.drawEllipse(QPoint(150, 150), 100, 100);
//    image.save("E:/code/QT/13_QPainter/image/04.png");

    // 可以记录绘图和重现指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    pic.save("E:/code/QT/13_QPainter/image/05.zt");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter2(this);
    QPicture pic2;
    pic2.load("E:/code/QT/13_QPainter/image/05.zt");
    painter2.drawPicture(0, 0, pic2);
}

