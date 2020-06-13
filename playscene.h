#pragma once

#include <QMainWindow>
#include <QPainter>
#include "gamebutton.h"
#include "agumon.h"
#include "playscenebutton.h"
#include "digimonposition.h"
#include "waypoint.h"
#include "smalldevilmon.h"
class Fire;
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent*e);
    void loadDigimonPosition();
    void connect_agumon_setbtn();
    void connect_agumon_removebtn();
    void connect_agumon_levelup();
    void addWayPoints();
    bool loadDevilmonWave();
    void removeDevilmon(SmallDevilmon* devilmon);
    void drawBasementHp(QPainter*painter);
    void drawCurrentWave(QPainter*painter);
    void drawGold(QPainter*painter);
    void getDamage(int damage = 1);
    void addFire(Fire * smallfire);
    void removeFire(Fire*smallfire);
    bool judgeGold(int gold);
    QList<SmallDevilmon*> devilmonList();
    int basementHp;
    int goldNum;
    int current_waves;
private:
    QList <DigimonPosition*> digimon_position_list;
    QList<Agumon*> agumon_list;
    QList<WayPoint*> waypoint_list_one;
    QList<SmallDevilmon*> smalldevilmon_list;
    QList<Fire*> fire_list;
    GameButton * back_btn;
private slots:
     void startGame();
     void updateScence();
signals:
     void chooseBack();
};

