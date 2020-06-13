#include "smalldevilmon.h"
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include "waypoint.h"
#include "agumon.h"
#include "playscenebutton.h"
#include <QVector2D>
#include <QDebug>
#include <QtMath>
#include "playscene.h"
static const int HP_BAR = 20;
const QSize SmallDevilmon::e_fixedSize(50,40);
SmallDevilmon::SmallDevilmon(WayPoint* startWayPoint, PlayScene*game,const QPixmap &pixmap ):
    QObject(0),
    e_active(false),
    e_maxHp(30),
    e_currentHp(30),
    speed(1.0),
    e_pos(startWayPoint->pos()),
    e_destinationPoint(startWayPoint->nextWayPoint()),
    e_game(game),
    e_pixmap(pixmap)
{
}

SmallDevilmon::~SmallDevilmon(){
    e_destinationPoint = NULL;
    e_game = NULL;
}
void SmallDevilmon::doActive(){
    e_active = true;
}
void SmallDevilmon::move(){
    if(!e_active){
        return ;
    }
    if(isCollision(e_pos,1,e_destinationPoint->pos(),1)){
        if(e_destinationPoint->nextWayPoint()){
            e_pos = e_destinationPoint->pos();
            e_destinationPoint = e_destinationPoint->nextWayPoint();
        }//没有下一个点表示已经进入基地了调用基地受伤害以及敌人移除
        else
        {
            e_game->getDamage();
            e_game->removeDevilmon(this);
           return ;
      }
    }
    QPoint t_point = e_destinationPoint->pos();
    qreal moveSpeed = speed;
    QVector2D normalized(t_point - e_pos);
    normalized.normalize();
    e_pos = e_pos + normalized.toPoint()*moveSpeed;

}
void SmallDevilmon::draw(QPainter *painter) const{
    if(!e_active)
        return;
    painter->save();
    QPoint healthBarPoint = e_pos+QPoint(-HP_BAR/2-5,-e_fixedSize.height());
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarRect(healthBarPoint,QSize(HP_BAR,2));
    painter->drawRect(healthBarRect);
    painter->setBrush(Qt::green);
    QRect healBarLiveRect(healthBarPoint,QSize((double)e_currentHp/e_maxHp*HP_BAR,2));
    painter->drawRect(healBarLiveRect);
    QPoint toSub(-e_fixedSize.width()/2,-e_fixedSize.height()/2);
    painter->translate(e_pos);
    painter->drawPixmap(toSub, e_pixmap);
    painter->restore();
}
 bool SmallDevilmon:: isCollision(QPoint p1, int r1,QPoint p2,int r2){
    int dx = p1.x()-p2.x();
    int dy = p1.y()-p2.y();
    int distance = qSqrt(dx*dx+dy*dy);
    if(distance <= r1+r2)
        return true;
    return false;

}
 QPoint SmallDevilmon::pos() const{
     return e_pos;
 }
 void SmallDevilmon::getDamage(int damage){
    e_currentHp-=damage;
    if(e_currentHp<=0){
        getRemoved();
    }
 }
 void SmallDevilmon::getRemoved(){
   if(attack_agumon_list.empty()){
       return;
   }
   foreach(Agumon * agumon, attack_agumon_list)
       agumon->targetKilled();
   e_game->goldNum+=100;
   e_game->removeDevilmon(this);
 }
 void SmallDevilmon::getAttacked(Agumon *attacker){
         attack_agumon_list.push_back(attacker);
 }
 void SmallDevilmon::gotLostSight(Agumon *attacker){
  attack_agumon_list.removeOne(attacker);
 }
