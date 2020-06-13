#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QWidget>
#include <QPushButton>
class GameButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GameButton(QWidget *parent = nullptr);
    GameButton(QString normalImg, QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;
    void zoomup();
    void zoomdown();
signals:

};

#endif // GAMEBUTTON_H
