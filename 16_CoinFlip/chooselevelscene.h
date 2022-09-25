#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playsence.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);
    PlaySence *play = nullptr;

signals:
    // 告诉主场景，点击了返回的信号
    void chooseSenceBack();

};

#endif // CHOOSELEVELSCENE_H
