#include "playscenebutton.h"
#include <QPainter>
PlaySceneButton::PlaySceneButton(QWidget * parent) :QPushButton(parent)
{
    connected_agumon = NULL;
    QPixmap pix = QPixmap(":/SSJH.png");
    //设置图片固定大小
    this->setFixedSize( pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
this->setContextMenuPolicy(Qt::ActionsContextMenu);
setGabumon = new QAction(this);
setAgumon = new QAction(this);
removeDigimon = new QAction(this);
levelUp = new QAction(this);
setAgumon->setText("购买亚古兽");
setGabumon->setText("购买加布兽");
removeDigimon->setText("移除");
levelUp->setText("升级");
addAction(setAgumon);
addAction(setGabumon);
addAction(levelUp);
addAction(removeDigimon);
connect(setAgumon,&QAction::triggered,this,[=](){
    emit set_digimon(0);
});
connect(setGabumon,&QAction::triggered,this,[=](){
    emit set_digimon(1);
});
connect(removeDigimon,&QAction::triggered,this,[=](){
    emit remove_digimon();
});
connect(levelUp,&QAction::triggered,this,[=](){
    if(connected_agumon)
    emit level_up_digimon();
});
}
