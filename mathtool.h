#ifndef MATHTOOL_H
#define MATHTOOL_H

#endif // MATHTOOL_H
#include <QtMath>
#include <QPoint>
#include <QDebug>
inline bool isCollision(QPoint p1, int r1,QPoint p2,int r2){
    int dx = p1.x()-p2.x();
    int dy = p1.y()-p2.y();
    int distance = qSqrt(dx*dx+dy*dy);
    if(distance <= r1+r2)
        return true;
    return false;
}
