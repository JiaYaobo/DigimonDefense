#include "playscene.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include "playscenebutton.h"
#include<QPainter>
#include "digimonposition.h"
#include <QList>
#include <QTimer>
#include "fire.h"
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
  ,current_waves(0)
{
    goldNum = 1000;
    basementHp = 50;
    this->setFixedSize(800,600);
    back_btn = new GameButton(":/BackButton.png");
    back_btn->setParent(this);
    back_btn->move(720,0);
    loadDigimonPosition();
    addWayPoints();
    connect_agumon_setbtn();
    connect_agumon_removebtn();
    connect_agumon_levelup();
    connect(back_btn,&QPushButton::clicked,this,[=](){
        emit chooseBack();
    });
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateScence()));
    timer->start(10);
    startGame();
}
void PlayScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/levelOneScene.png");
    QPixmap status(":/StatusBar.jpg");
    painter.drawPixmap(0,0,this->width(),this->height()/1.5,pixmap);
    painter.drawPixmap(0,400,800,200,status);
    drawBasementHp(&painter);
    drawGold(&painter);
    drawCurrentWave(&painter);
    foreach( Agumon * agu, agumon_list)
        agu->draw(&painter);
     foreach(WayPoint* wayPoint , waypoint_list_one)
         wayPoint->draw(&painter);
     foreach(SmallDevilmon*devilmon,smalldevilmon_list){
         devilmon->draw(&painter);}
     foreach(Fire*fire, fire_list)
         fire->draw(&painter);
}
void PlayScene::mousePressEvent(QMouseEvent *e){
    qDebug()<<"x = "<<e->x()<<"y = "<<e->y();
}
void PlayScene::loadDigimonPosition(){
    QPoint posb1[]={QPoint(300,75),QPoint(575,75),QPoint(650,300),QPoint(440,300),QPoint(180,300),QPoint(70,75)};
    QPoint posd1[]={QPoint(300,100),QPoint(575,100),QPoint(650,250),QPoint(440,250),QPoint(180,250),QPoint(70,100)};
    int len1 = sizeof(posb1)/sizeof(posb1[0]);
    for(int i = 0;i<len1;i++){
        DigimonPosition *  pos1 = new DigimonPosition(posb1[i],posd1[i]);
        digimon_position_list.push_back(pos1);
        pos1->pBtn->setParent(this);
        pos1->pBtn->move(pos1->b_pos);
    }
}
void PlayScene::connect_agumon_setbtn(){
    for(int i=0;i<digimon_position_list.size();i++){
        connect(digimon_position_list[i]->pBtn,&PlaySceneButton::set_digimon,this,[=](int j){
            if(!digimon_position_list[i]->hasDigimon()&&judgeGold(Agumon::setAgumonCost)){
            digimon_position_list[i]->setHasDigimon(true);
            Agumon * agu = new Agumon(this,j);
            goldNum-=Agumon::setAgumonCost;
            digimon_position_list[i]->pBtn->connected_agumon = agu;
            agu->setAgumonPos(digimon_position_list[i]->d_pos);
            agu->setcentrPos();
            agumon_list.push_back(agu);
            update();
            }
        });
    }
}
void PlayScene::connect_agumon_removebtn(){
    for(int i =0;i<digimon_position_list.size();i++){
        connect(digimon_position_list[i]->pBtn,&PlaySceneButton::remove_digimon,this,[=](){
           agumon_list.removeOne(digimon_position_list[i]->pBtn->connected_agumon);
           update();
        });
    }
}
void PlayScene::connect_agumon_levelup(){
    for (int i=0;i<digimon_position_list.size();i++) {
        connect(digimon_position_list[i]->pBtn,&PlaySceneButton::level_up_digimon,this,[=](){
            digimon_position_list[i]->pBtn->connected_agumon->evolution();
            update();
        });
    }
}
void PlayScene::addWayPoints(){
    WayPoint * wayPoint1 = new WayPoint(QPoint(750,200));
    waypoint_list_one.push_back(wayPoint1);
    WayPoint * wayPoint2 = new WayPoint(QPoint(30,200));
    waypoint_list_one.push_back(wayPoint2);
    wayPoint1->setNextWayPoint(wayPoint2);
}
void PlayScene::removeDevilmon(SmallDevilmon*devilmon){
    smalldevilmon_list.removeOne(devilmon);
    delete  devilmon;
    if(smalldevilmon_list.empty()){
        ++current_waves;
        update();
       if( loadDevilmonWave()){}
    }
}
void PlayScene::updateScence(){
    foreach(SmallDevilmon* devilmon , smalldevilmon_list){
        devilmon->move();
    }
    foreach(Agumon*agumon,agumon_list)
        agumon->checkDevilmonInRange();
    update();
}
bool PlayScene::loadDevilmonWave(){
    if(current_waves>=3){
        return false;
    }
    WayPoint*startPoint = waypoint_list_one.first();
    int devilmonInterval[]={1000,6000,11000};
    for(int i=0;i<3;i++){
        SmallDevilmon * devilmon = new SmallDevilmon(startPoint,this);
        smalldevilmon_list.push_back(devilmon);
        QTimer::singleShot(devilmonInterval[i],devilmon,SLOT(doActive()));
    }
    return true;
}
void PlayScene::startGame(){
    loadDevilmonWave();
}
void PlayScene::drawGold(QPainter *painter){
    painter->save();
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(240,470,90,50),QString("GOLD : %1").arg(goldNum));
    painter->restore();
}
void PlayScene::drawCurrentWave(QPainter *painter){
    painter->save();
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(440,470,90,50),QString("WAVES : %1").arg(current_waves));
    painter->restore();
}
void PlayScene::drawBasementHp(QPainter *painter){
    painter->save();
    painter->setPen(QPen(Qt::red));
    painter->drawText(QRect(40,470,90,50),QString("HP : %1").arg(basementHp));
    painter->restore();
}
void PlayScene::getDamage(int damage){
     this->basementHp-=damage;
    return ;
}
QList<SmallDevilmon*> PlayScene::devilmonList(){
    return smalldevilmon_list;
}
void PlayScene::addFire(Fire *smallfire){
    Q_ASSERT(smallfire);
    fire_list.push_back(smallfire);
}
void PlayScene::removeFire(Fire *smallfire){
    Q_ASSERT(smallfire);
    fire_list.removeOne(smallfire);
    delete  smallfire;
}
bool PlayScene::judgeGold(int gold){
    if(this->goldNum>=gold){
        return true;
    }
    return false;
}
