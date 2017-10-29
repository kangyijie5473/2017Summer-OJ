/*
 * > File Name: Hero.h
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月29日 星期日 10时00分32秒
 */

#ifndef _HERO_H
#define _HERO_H
#include "Minion.h"
#include <vector>
using namespace std;
class Minion;
class Hero{
public:
    Hero():hp(30){};
    Hero(const Hero&) = delete;
    Hero &operator=(Hero &) = delete;
    ~Hero() = default;
    int hp;
    int attack(Hero &enemy, int minionNum, int enemyNum);
    int underAttack(int minionNum, int attackNum);
    void summon(int postion, int attackNum, int hp);
    void printMinion();
private:
    void judgeMinion(int minionNum);
    vector<Minion> minionList;
    Minion &getMinion(int minionNum);
};
#endif
