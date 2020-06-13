#include "chooselevelscene.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include "gamebutton.h"
#include <QPushButton>
#include <QTimer>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
  this->setFixedSize(800,600);
    back_button = new GameButton(":/BackButton.png");
    back_button->setParent(this);
    back_button->move(720,500);
    scene_1st = new GameButton(":/levelone.png");
    scene_1st->setParent(this);
    scene_1st->move(20,200);

    connect(scene_1st,&QPushButton::clicked,this,[=](){
        scene_1= new PlayScene;
        scene_1st->zoomup();
        scene_1st->zoomdown();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            scene_1->show();
        });
        connect(scene_1,&PlayScene::chooseBack,this,[=](){
            scene_1->hide();
            this->show();
             delete scene_1;
        });
    });
    connect(back_button,&QPushButton::clicked,this,[=](){
        emit chooseSceneBack();
    });
}
void ChooseLevelScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix(":/ChooseLevelPicture.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
void ChooseLevelScene::mousePressEvent(QMouseEvent *e){
    qDebug()<<"x = "<<e->x()<<"y = "<<e->y();
}
