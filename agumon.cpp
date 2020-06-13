#include "agumon.h"
#include <QPainter>
#include "playscene.h"
#include"smalldevilmon.h"
#include "QtMath"
#include "QDebug"
#include "fire.h"
#include <QTimer>
 int Agumon::setAgumonCost = 100;
Agumon::Agumon(PlayScene * game, int chooseWho):
    QObject(0),
    a_game(game),
    chosenDevilmon(NULL)
{
  digimon_info = new DigimonInfo(chooseWho);
   fireRateTimer = new QTimer(this);
   connect(fireRateTimer,SIGNAL(timeout()),this,SLOT(fireFire()));
}
void Agumon::draw(QPainter *painter){
    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(centrPos,getAttackRadius(),getAttackRadius());
   painter->drawPixmap(pos,QPixmap(digimon_info->_levelImages[getLevel()-1]));
    painter->restore();
}
void Agumon::evolution(){
    if(this->getLevel()>=3)
        return;
    int current_level = getLevel();
    setLevel(current_level+1);
    powerUp();
}
void Agumon::setcentrPos(){
    QPoint toSub(-QPixmap(digimon_info->_levelImages[getLevel()-1]).width()/2,
           -QPixmap(digimon_info->_levelImages[getLevel()-1]).height()/2);
    this->centrPos = pos-toSub;
}
void Agumon::setAgumonPos(QPoint Apos){
    this->pos = Apos;
}
QPoint Agumon::getCentPos(){
    return this->centrPos;
}
void Agumon::removeFire(){
}
void Agumon::chooseTarget(SmallDevilmon *devilmon){
    chosenDevilmon = devilmon;
    attackTarget();
    chosenDevilmon->getAttacked(this);
}
void Agumon::attackTarget(){
     fireRateTimer->start(this->getAttackF());
}
void Agumon::targetKilled(){
     if(chosenDevilmon)
         chosenDevilmon = NULL;
     fireRateTimer->stop();
}
void Agumon::lostSightOfTarget(){
    chosenDevilmon->gotLostSight(this);
    if(chosenDevilmon)
        chosenDevilmon = NULL;
    fireRateTimer->stop();
}
void Agumon::checkDevilmonInRange(){
  if(chosenDevilmon){
      if(!judgeCollision(pos,this->getAttackRadius(),chosenDevilmon->pos(),1)){
          lostSightOfTarget();
      }
  }
  else
  {
      QList<SmallDevilmon*> devilmon_list = a_game->devilmonList();
      foreach(SmallDevilmon* devilmon, devilmon_list){
          if(judgeCollision(pos,this->getAttackRadius(),devilmon->pos(),5)){
          chooseTarget(devilmon);
          break;
          }
      }
  }
}
bool Agumon::judgeCollision(QPoint p1, int r1, QPoint p2, int r2){
    int dx = p1.x()-p2.x();
    int dy = p1.y()-p2.y();
    int distance = qSqrt(dx*dx+dy*dy);
    if(distance <= r1+r2)
        return true;
    return false;
}
void Agumon::fireFire(){
    Fire* fire = new Fire(centrPos,chosenDevilmon->pos(),this->getDamage(),chosenDevilmon,a_game);
    fire->move();
    a_game->addFire(fire);
}
int Agumon::getSetAgumonCost(){
    return this->setAgumonCost;
}

void Agumon::powerUp(){
    this->setDamage(digimon_info->_abilityMap["attackDamage"][getLevel()-1]);
    this->setAttackF(digimon_info->_abilityMap["attackF"][getLevel()-1]);
    this->setAttackRadius(digimon_info->_abilityMap["attackRadius"][getLevel()-1]);
}
