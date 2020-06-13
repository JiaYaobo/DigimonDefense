#ifndef DIGIMON_H
#define DIGIMON_H
#include <QString>
#include <QPixmap>
#include <QObject>
class Digimon
{
public:
    Digimon();
    void setLevel(int level);
    void setAttackRadius(int radius);
    void setAttackF(int f);
    void setHP(int hp);
    void setDamage(int damage);
    int getLevel(){return level;}
    int getAttackRadius(){return attack_radius;}
    int getAttackF(){return attack_f;}
    int getCurrentHP(){return HP;}
    int getDamage(){return damage;}
private:
    int damage;
    int level;//数码兽等级
    int attack_radius;//攻击半径
    int attack_f;//攻击频率
    int HP = 0;//血量，怪兽有
};

#endif // DIGIMON_H
