/*
 * > File Name: Minion.h
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月29日 星期日 09时59分41秒
 */

#ifndef _MINION_H
#define _MINION_H
#include "Hero.h"
class Hero;
class Minion{
public:

    Minion(int Id, int AttackNum, int Hp): id(Id), attackNum(AttackNum),hp(Hp){}
    void attack(Hero & enemy, int id);
    int id;
    int hp;
    int attackNum;

};
#endif
