/*
 * > File Name: hearthstone.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月28日 星期六 22时30分56秒
 */

#include <iostream>
#include <vector>
using namespace std;
class Hero;
class Minion{
public:

    Minion(int Id, int AttackNum, int Hp): id(Id), attackNum(AttackNum),hp(Hp){}
    void attack(Hero & enemy, int id);
    int id;
    int hp;
    int attackNum;

};
void Minion::attack(Hero &enemy, int id)
{
    if(!id){
        enemy.hp--;
        return
    }
    attack = enemy.underAttack(id, this->attackNum);
    this->hp -= attack;
}
class Hero{
public:
    Hero() = default;
    Hero(const Hero&) = delete;
    Hero &operator=(Hero &) = delete;
    ~Hero() = default;
    int hp;
    int attack(Hero &enemy, int minionNum, int enemyNum);
    int underAttack(int minionNum, int attackNum);
    void summon(int postion, int attackNum, int hp);
    void printMinion();
private:
    void judgeMinion(Minion &);
    vector<Minion> minionList;
    Minion &getMinion(int minionNum);
};
int Hero::underAttack(int minionNum, int attackNum)
{
    getMinion(minionNum).hp -= attackNum;
    return getMinion(minionNum).attackNum;
}
void Hero::judgeMinion(Minion &minion)
{
    for(auto i = minionList.begin(); i != minionList.end(); i++)
        if(i->hp <= 0){
            minionList.erase(i);
            return;
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
    for(auto minion : minionList){
        if(minion.id == minionNum) // to do : some error probably
            return minion;
    }
}
void Hero::printMinion()
{
    cout << minionList.size() << " ";
    for(int i = 1; i <= minionList.size(); i++){
        cout << getMinion(i).hp << " ";
    }
}
int Hero::attack(Hero &enemy, int minionNum, int enemyNum)
{
    getMinion(minionNum).attack(enemy, enemyNum);
    judgeMinion(getMinion(minionNum));
    return 0;
}
void judgeHero(Hero &first, Hero &second){
    if(first.hp > 0 && second.hp > 0){
        cout << 0 << endl;
        return ;
    }
    if(first.hp){
        cout << 1 << endl;
        return;
    }else{
        cout << -1 << endl;
        return;
    }

}
int main(void)
{
    Hero player_first;
    Hero player_second;
    int n,postion, attackNum, hp, attacker, defender;
    cin >> n;
    string cmd;
    while(n){
        while(n){
            cin >> cmd;
            if(cmd == "end"){
                n--;
                break;
            }
            if(cmd == "summon"){
                cin >> postion >> attackNum >> hp;
                player_first.summon(postion, attackNum, hp);
                n--;
                continue;
            }
            if(cmd == "attack"){
                cin >> attacker >> defender;
                player_first.attack(player_second, attacker, defender);
                n--;
                continue;
            }
        }
        while(n){
            cin >> cmd;
            if(cmd == "end"){
                n--;
                break;
            }
            if(cmd == "summon"){
                cin >> postion >> attackNum >> hp;
                player_second.summon(postion, attackNum, hp);
                n--;
                continue;
            }
            if(cmd == "attack"){
                cin >> attacker >> defender;
                player_second.attack(player_second, attacker, defender);
                n--;
                continue;
            }
        }
    }
    judgeHero(player_first, player_second);
    cout << player_first.hp << endl;
    player_first.printMinion();
    cout << player_second.hp << endl;
    player_second.printMinion();
}
