#ifndef AGUMON_H
#define AGUMON_H
#include "digimon.h"
#include <QPoint>
#include <QTimer>
#include <QObject>
#include "digimoninfo.h"
class PlayScene;
class SmallDevilmon;
class Fire;
class Agumon :public QObject, public Digimon
{
    Q_OBJECT
public:
    Agumon(PlayScene* game, int chooseWho);
    void draw(QPainter* painter);
    void evolution();
    void setcentrPos();
    void setAgumonPos(QPoint Apos);
    QPoint getCentPos();
    void checkDevilmonInRange();
    void targetKilled();
    void attackTarget();
    void chooseTarget(SmallDevilmon *devilmon);
    void removeFire();
    void damageTarget();
    void lostSightOfTarget();
    bool judgeCollision(QPoint p1, int r1,QPoint p2,int r2);
    int getSetAgumonCost();
    void powerUp();
      static  int setAgumonCost;
 private:
    PlayScene * a_game;
    SmallDevilmon * chosenDevilmon;
    QPoint pos = QPoint(100,100);
    QPoint centrPos = QPoint(100,100);
    QTimer * fireRateTimer;
    DigimonInfo *digimon_info;
private slots:
    void fireFire();
};

#endif // AGUMON_H



