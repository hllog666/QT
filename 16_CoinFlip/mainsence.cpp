#include "mainsence.h"
#include "./ui_mainsence.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QSoundEffect>

MainSence::MainSence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币主场景");

    connect(ui->actionquit, &QAction::triggered, [=]() {
        this->close();
    });

    // 音效
    QSoundEffect *startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));

    // 开始按钮
    MyPushButton *startButton = new MyPushButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width() * 0.5 - startButton->width() * 0.5, this->height() * 0.7);

    chooseScene = new ChooseLevelScene;

    connect(chooseScene, &ChooseLevelScene::chooseSenceBack, this, [=]() {
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });

    connect(startButton, &MyPushButton::clicked, [=]() {
        qDebug() << "开始";
        startSound->play();
        startButton->zoom1();
        startButton->zoom2();

        // 进入选择关卡场景
        QTimer::singleShot(500, this, [=]() {
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();

        });

    });
}

MainSence::~MainSence()
{
    delete ui;
}

void MainSence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix);
}

