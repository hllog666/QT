#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置鼠标追踪
    setMouseTracking(true);
}

void MyLabel::enterEvent(QEnterEvent *event)
{
    qDebug() << "鼠标进入";
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开";
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "鼠标移动";
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug() << "鼠标按下";
    QString str = QString("x = %1 y = %2 globalX = %3 globalY = %4")
            .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << "鼠标释放";
}

bool MyLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event x = %1 y = %2 globalX = %3 globalY = %4")
                .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
    return QLabel::event(e);
}
