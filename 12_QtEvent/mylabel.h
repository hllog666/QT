#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QEnterEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入事件
    void enterEvent(QEnterEvent *event);
    // 鼠标离开事件
    void leaveEvent(QEvent *event);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
