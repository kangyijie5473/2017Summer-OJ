/*
 * > File Name: Hero.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月29日 星期日 10时02分03秒
 */

#include <iostream>
#include "Hero.h"
using namespace std;
int Hero::underAttack(int minionNum, int attackNum)
{
    getMinion(minionNum).hp -= attackNum;
    int couterAttackNum = getMinion(minionNum).attackNum;
    judgeMinion(minionNum);
    return couterAttackNum;
}
void Hero::judgeMinion(int minionNum)
{
    bool flag = false;
    for(auto i = minionList.begin(); i != minionList.end(); ){
        if(i->hp <= 0){
            i = minionList.erase(i);
            flag = true;
            continue;
        }
        i++;
    }
    if(flag){
        for(auto i = minionList.begin(); i != minionList.end(); i++)
            if(i->id > minionNum)
                i->id--;
    }
}

void Hero::summon(int postion, int attackNum, int hp)
{
    for(auto i = minionList.begin(); i != minionList.end(); i++){
        if(i->id >= postion)
            i->id++;
    }
    minionList.push_back(Minion(postion, attackNum, hp));
}
Minion &Hero::getMinion(int minionNum)
{
    for(auto minion = minionList.begin();
        minion != minionList.end();
        minion++)
        if(minion->id == minionNum)
            return *minion;
}
void Hero::printMinion()
{
    cout << minionList.size() << " ";
    for(int i = 1; i <= minionList.size(); i++){
        cout << getMinion(i).hp << " ";
    }
    cout << endl;
}
int Hero::attack(Hero &enemy, int minionNum, int enemyNum)
{
    getMinion(minionNum).attack(enemy, enemyNum);
    judgeMinion(minionNum);
    return 0;
}
