#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>
#include "gamebutton.h"
#include <QTimer>
#include "chooselevelscene.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     init_game();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *){//画主界面
    QPainter painter(this);
    QPixmap pixmap(":/MainWindowBackground.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton){
        qDebug()<<"x= "<<event->x()<<"y= "<<event->y();
    }
}
void MainWindow::init_game(){
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("DigimonDefense");
    begin_button = new GameButton(":/BeginButton.png");
    choose_level_scene = new ChooseLevelScene;
    begin_button->setParent(this);
    begin_button->move(500,80);
    connect(begin_button,&QPushButton::clicked,this,[=](){
        begin_button->zoomup();
        begin_button->zoomdown();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            choose_level_scene->show();
        });
    });
    connect(choose_level_scene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        choose_level_scene->hide();
        this->show();
    });
}
