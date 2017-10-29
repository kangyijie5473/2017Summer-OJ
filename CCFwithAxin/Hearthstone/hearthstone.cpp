/*
 * > File Name: hearthstone.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月28日 星期六 22时30分56秒
 */

#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;
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
                player_second.attack(player_first, attacker, defender);
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
