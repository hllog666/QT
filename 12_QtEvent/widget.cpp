#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=]() {
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });

    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        timer->stop();
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
        timer->start(500);
    });

    // 事件过滤器
    ui->label->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *ev)
{
    if (ev->timerId() == id1)
    {
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    }
    else
    {
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));
    }
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == ui->label)
    {
        if (e->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev = static_cast<QMouseEvent *>(e);
            QString str = QString("eventFilter x = %1 y = %2 globalX = %3 globalY = %4")
                    .arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
            qDebug() << str;
        }
    }
    return QWidget::eventFilter(obj, e);
}
