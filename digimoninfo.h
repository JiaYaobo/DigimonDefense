
#ifndef DIGIMONINFO_H
#define DIGIMONINFO_H

#include <QObject>
#include <QPixmap>
#include <QPoint>
#include <QDebug>
#include <QVector>
#include <QMap>
class DigimonInfo : public QObject
{
    Q_OBJECT
public:
     DigimonInfo(int chooseWho);
     QVector<QString>_levelImages;
     QMap<QString, QVector<int>>_abilityMap;
     void loadAgumonInfo();
     void loadGabumonInfo();
signals:

};

#endif // DIGIMONINFO_H
