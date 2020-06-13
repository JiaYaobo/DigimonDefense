#ifndef FIRE_H
#define FIRE_H

#include <QObject>
#include <QSize>
#include <QPixmap>
#include <QPainter>
class SmallDevilmon;
class PlayScene;

class Fire : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint f_currentPos READ currentPos WRITE setCurrentPos )
public:
Fire(QPoint startPos,QPoint targetPos,int damage,
     SmallDevilmon * target,PlayScene*game,
     QPixmap pixmap = QPixmap(":/fire.png"));
void draw(QPainter * painter) ;
void move();
void setCurrentPos(QPoint pos);
QPoint currentPos();
 private:
    QPoint f_startPos;
    QPoint f_targetPos;
    QPixmap fire;
    QPoint f_currentPos;
    SmallDevilmon * tartgetDevilmon;
    PlayScene * f_game;
    int f_damage;
    static const QSize f_fixedsize;
private slots:
    void hitTarget();
signals:

};

#endif // FIRE_H
