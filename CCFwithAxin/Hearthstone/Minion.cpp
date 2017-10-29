/*
 * > File Name: Minion.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月29日 星期日 10时01分24秒
 */

#include <iostream>
#include "Minion.h"
using namespace std;
void Minion::attack(Hero &enemy, int id)
{
    if(!id){
        enemy.hp -= this->attackNum;
        return;
    }
    int attack;
    attack = enemy.underAttack(id, this->attackNum);
    this->hp -= attack;
}

