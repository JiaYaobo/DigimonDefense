#include "digimoninfo.h"

DigimonInfo::DigimonInfo( int chooseWho) : QObject(0)
{
   if(chooseWho == 0){
                loadAgumonInfo();
            }
      else if(chooseWho == 1){
                loadGabumonInfo();
            }
}

void DigimonInfo::loadAgumonInfo(){
   _levelImages.push_back(":/Agumon.png");
    _levelImages.push_back(":/Greymon.png");
    _levelImages.push_back(":/IronGreymon.png");
            QVector<int> attackRadius;
            attackRadius.push_back(125);
            attackRadius.push_back(150);
            attackRadius.push_back(175);
   _abilityMap["attackRadius"] = attackRadius;
            QVector <int>attackDamage;
            attackDamage.push_back(10);
            attackDamage.push_back(40);
            attackDamage.push_back(60);
     _abilityMap["attackDamage"] = attackDamage;
     QVector<int> attackF;
     attackF.push_back(800);
     attackF.push_back(600);
     attackF.push_back(400);
     _abilityMap["attackF"]=attackF;
}

 void DigimonInfo::loadGabumonInfo(){
            _levelImages.push_back(":/Gabumon.png");
             _levelImages.push_back(":/Galulumon.png");
             _levelImages.push_back(":/IronGalulu.png");
                     QVector<int> attackRadius;
                     attackRadius.push_back(125);
                     attackRadius.push_back(150);
                     attackRadius.push_back(175);
            _abilityMap["attackRadius"] = attackRadius;
                     QVector <int>attackDamage;
                     attackDamage.push_back(10);
                     attackDamage.push_back(40);
                     attackDamage.push_back(60);
              _abilityMap["attackDamage"] = attackDamage;
              QVector<int> attackF;
              attackF.push_back(800);
              attackF.push_back(600);
              attackF.push_back(400);
              _abilityMap["attackF"]=attackF;
        }



