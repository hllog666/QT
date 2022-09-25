#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QSoundEffect>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡场景");

    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=]() {
        this->close();
    });

    QSoundEffect *chooseSound = new QSoundEffect(this);
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    QSoundEffect *backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

    MyPushButton *backButton = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backButton->setParent(this);
    backButton->move(this->width() - backButton->width(), this->height() - backButton->height());

    connect(backButton, &MyPushButton::clicked, [=]() {
        backSound->play();
        qDebug() << "返回";
        QTimer::singleShot(500, this, [=]() {
            emit this->chooseSenceBack();
        });
    });

    for (int i = 0; i < 20; i++)
    {
        MyPushButton *menuButton = new MyPushButton(":/res/LevelIcon.png");
        menuButton->setParent(this);
        menuButton->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        // 点击事件
        connect(menuButton, &MyPushButton::clicked, [=]() {
            chooseSound->play();
            QString str = QString("第%1关").arg(i + 1);
            qDebug() << str;

            // 进入游戏
            this->hide();
            play = new PlaySence(i + 1);
            play->show();
            play->setGeometry(this->geometry());

            connect(play, &PlaySence::chooseSenceBack, [=]() {
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = nullptr;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuButton->width(), menuButton->height());
        label->setText(QString::number(i + 1));
        label->move(25 + i % 4 * 70, 130 + i / 4 * 70);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix);
}
