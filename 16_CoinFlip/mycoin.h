#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    // explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);

    void changeFlag();

    int posX;
    int posY;
    // 正反
    bool flag;
    // 正->反
    QTimer *timer1;
    // 反->正
    QTimer *timer2;
    int min = 1;
    int max = 8;
    bool isAnimation = false;
    bool isWin = false;

    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // MYCOIN_H
