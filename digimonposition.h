#ifndef DIGIMONPOSITION_H
#define DIGIMONPOSITION_H
#include <QPoint>
#include <QPainter>
#include "playscenebutton.h"
class DigimonPosition
{
public:
    DigimonPosition(QPoint posb,QPoint posd);
    void setHasDigimon(bool hasDigimon = true);//建立数码兽的时候调用
    bool hasDigimon() const;//查看是否在数码兽位置上有数码兽
    QPoint  b_pos;//按钮位置
    QPoint   d_pos;//数码兽位置
    bool d_has_digimon ;//判断按钮关联的数码兽位置是否有数码兽了，初始false
    PlaySceneButton * pBtn;
};

#endif // DIGIMONPOSITION_H
