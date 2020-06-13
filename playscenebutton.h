#ifndef PLAYSCENEBUTTON_H
#define PLAYSCENEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QAction>
#include "agumon.h"
class PlaySceneButton : public QPushButton
{
    Q_OBJECT
public:
   PlaySceneButton(QWidget * parent = nullptr);
   Agumon * connected_agumon;
   QAction * setAgumon;
   QAction * setGabumon;
   QAction * removeDigimon;
   QAction * levelUp;
private:
signals:
   void set_digimon(int i);
   void remove_digimon();
   void level_up_digimon();

};

#endif // PLAYSCENEBUTTON_H
