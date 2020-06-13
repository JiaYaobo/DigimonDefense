#include "digimon.h"
#include <QPoint>
#include <QPainter>
Digimon::Digimon()
{
    this->level = 1;
    this->attack_f = 800;
    this->attack_radius = 125;
    this->damage = 10;
}
void Digimon::setLevel(int level){
    this->level = level;
}
void Digimon::setAttackF(int f){
    this->attack_f =f;
}
void Digimon::setAttackRadius(int radius){
    this->attack_radius = radius;
}
void Digimon::setHP(int hp){
    this->HP = hp;
}
void Digimon::setDamage(int damage){
    this->damage = damage;
}
