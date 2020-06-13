#include "digimonposition.h"
#include <QPoint>
#include <QPainter>
DigimonPosition::DigimonPosition(QPoint posb,QPoint posd):b_pos(posb),d_pos(posd)
{
 d_has_digimon = false;
 pBtn = new PlaySceneButton;
}
bool DigimonPosition::hasDigimon() const{
    return d_has_digimon;
}
void DigimonPosition::setHasDigimon(bool hasDigimon){
    this->d_has_digimon = hasDigimon;
}
