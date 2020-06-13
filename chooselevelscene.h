#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "gamebutton.h"
#include "playscene.h"
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
   virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent *e);
private:
    GameButton* back_button;
    GameButton * scene_1st;
    PlayScene * scene_1;
signals:
  void chooseSceneBack();
};

#endif // CHOOSELEVELSCENE_H
