#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "chooselevelscene.h"
#include "gamebutton.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent*);//重写绘画事件用来画主界面
     virtual void mousePressEvent(QMouseEvent*event);
    void init_game();
private:
    Ui::MainWindow *ui;
    GameButton * begin_button;
    ChooseLevelScene * choose_level_scene;
};
#endif // MAINWINDOW_H
