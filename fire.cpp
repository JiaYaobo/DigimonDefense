#include "fire.h"
#include "smalldevilmon.h"
#include "playscene.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QDebug>
const QSize Fire::f_fixedsize(15,15);
Fire::Fire(QPoint startPos,QPoint targetPos,int damage,
           SmallDevilmon * target,PlayScene*game,
           QPixmap pixmap ) :
    QObject(0)


{
    f_startPos = startPos;
    f_targetPos=targetPos;
     f_damage=damage;
    f_currentPos = startPos;
     tartgetDevilmon = target;
     f_game = game;
    fire = pixmap;
}
void Fire::draw(QPainter *painter){
    qDebug()<<f_currentPos.x();
    painter->drawPixmap(f_currentPos,fire);
}
void Fire::move(){
    static const int dur = 100;
    QPropertyAnimation * animation = new QPropertyAnimation(this,"f_currentPos");
  animation->setDuration(dur);
  animation->setStartValue(f_startPos);
  animation->setEndValue(f_targetPos);
  connect(animation,SIGNAL(finished()),this,SLOT(hitTarget()));
  animation->start();
}
void Fire::hitTarget(){
    if(f_game->devilmonList().indexOf(tartgetDevilmon)!=-1){
            tartgetDevilmon->getDamage(f_damage);
            f_game->removeFire(this);
    }
}

void Fire::setCurrentPos(QPoint pos){
    f_currentPos = pos;
}
QPoint Fire::currentPos(){
    return f_currentPos;
}
