#ifndef PLAYSENCE_H
#define PLAYSENCE_H

#include <QMainWindow>
#include "mycoin.h"

class PlaySence : public QMainWindow
{
    Q_OBJECT
public:
    // explicit PlaySence(QWidget *parent = nullptr);
    PlaySence(int levelNum);

    void paintEvent(QPaintEvent *);

    int levelIndex;

    int gameArray[4][4];
    MyCoin *coinBtn[4][4];
    bool isWin;

signals:
    void chooseSenceBack();

};

#endif // PLAYSENCE_H
