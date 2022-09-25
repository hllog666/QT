#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButton::MyPushButton(QWidget *parent)
//    : QPushButton{parent}
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if (!ret)
    {
        qDebug() << "图片加载失败";
        return;
    }
    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void MyPushButton::zoom1()
{
    // 动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    // 动画时间间隔
    animation->setDuration(200);
    // 起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    // 结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    // 缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 执行动画
    animation->start();
}

void MyPushButton::zoom2()
{
    // 动画对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    // 动画时间间隔
    animation->setDuration(200);
    // 起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    // 结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    // 缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 执行动画
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if (this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if (!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (this->pressImgPath != "")
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if (!ret)
        {
            qDebug() << "图片加载失败";
            return;
        }
        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
    }
    return QPushButton::mouseReleaseEvent(e);
}
