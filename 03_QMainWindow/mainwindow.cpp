#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600, 400);

    // 菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    QMenu *viewMenu = bar->addMenu("视图");

    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    // 工具栏
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    // 可以停靠的位置
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 取消浮动
    toolBar->setFloatable(false);
    // 设置移动
    toolBar->setMovable(true);
    // 设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);
    // 添加控件
    QPushButton *btn = new QPushButton("关闭");
    toolBar->addWidget(btn);

    // 状态栏
    QStatusBar *statusBar = new QStatusBar();
    setStatusBar(statusBar);
    QLabel *label = new QLabel("提示信息", this);
    statusBar->addWidget(label);
    QLabel *label2 = new QLabel("右侧提示信息", this);
    statusBar->addWidget(label2);

    // 铆接部件
    QDockWidget *dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    // 设置后期停靠位置
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // 中心部件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

