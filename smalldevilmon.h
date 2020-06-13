#pragma once

#include <QPoint>
#include <QObject>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include "waypoint.h"
#include "playscenebutton.h"
class PlayScene;
class Agumon;
class SmallDevilmon : public QObject
{
    Q_OBJECT
public:
    SmallDevilmon(WayPoint* startWayPoint, PlayScene*game,const QPixmap &pixmap =QPixmap(":/SmallDevilMon.png") );
   ~SmallDevilmon();
    void draw(QPainter* painter) const;
    void move();
    bool isCollision(QPoint p1, int r1,QPoint p2,int r2);
    void getDamage(int damage);
    void getRemoved();
    void getAttacked(Agumon * attacker);
    void gotLostSight(Agumon * attacker);
    QPoint pos() const;
public slots:
    void doActive();
private:
    bool e_active;
    int e_maxHp;
    int e_currentHp;
   qreal  speed;
   QPoint e_pos;
   WayPoint * e_destinationPoint;
   PlayScene * e_game;
   QList<Agumon*> attack_agumon_list;
   const QPixmap e_pixmap;
  static const QSize e_fixedSize;
};

