#include "waypoint.h"

WayPoint::WayPoint(QPoint pos): w_pos(pos),w_nextWayPoint(NULL)
{

}
void WayPoint::setNextWayPoint(WayPoint *nextPoint){
    w_nextWayPoint = nextPoint;
}
WayPoint*  WayPoint::nextWayPoint() const{
    return w_nextWayPoint;
}
const QPoint WayPoint::pos() const{
    return w_pos;
}
void WayPoint::draw(QPainter *painter) const{
    painter->save();
    painter->setPen(Qt::red);
    painter->drawEllipse(w_pos,6,6);
    painter->drawEllipse(w_pos,2,2);
    if(w_nextWayPoint){
        painter->drawLine(w_pos,w_nextWayPoint->w_pos);
    }
    painter->restore();
}
