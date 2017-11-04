/*
 * > File Name: stock.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年11月04日 星期六 09时56分42秒
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
const int CANCEL = 0;
const int BUY = 1;
const int SELL = 2;
struct Action{
    Action(int requset_type, double requset_price, int requset_amount): type(requset_type), price(requset_price),amount(requset_amount) {}

    int type;
    double price;
    int amount;
};
int main(void)
{
    map<double, int> buy;
    map<double, int> sell;
    vector<Action> action;
    double price;
    int amount;
    int num;
    //ios::sync_with_stdio(false);
    string cmd;
    while(cin >> cmd){
        if(cmd == "buy"){
            cin >> price >> amount;
            action.push_back(Action(BUY, price, amount));
        }
        if(cmd == "sell"){
           cin >> price >> amount; 
            action.push_back(Action(SELL, price, amount));
        }
        if(cmd == "cancel"){
            cin >> num;
            action[num - 1].type = CANCEL;
        }
    }
    for(vector<Action>::iterator i = action.begin(); i != action.end(); i++){
        if(i->type == CANCEL)
            continue;
        if(i->type == BUY){
            buy[i->price] += i->amount;
        }else
            sell[i->price] += i->amount;
    }
    /*
    for(auto i : buy)
        cout << i.first << ":" << i.second << endl;
    cout << endl;
    for(auto i : sell)
        cout << i.first << ":" << i.second << endl;
        */
    int temp;
    bool flag = true;
    for(map<double, int>::iterator i = --buy.end(); i != --buy.begin(); i--){
        if(flag){
            i--;
            flag = false;
        }
        i++;
        temp = i->second;
        i--;
        i->second += temp;

    }
    //cout << "buy" << endl;
    for(map<double, int>::iterator i = ++sell.begin(); i != sell.end(); i++){
        i--;
        temp = i->second;
        i++;
        i->second += temp;
    }
    //cout << "sell" << endl;
    double now_max_price = 0.0;
    int now_max_amount = 0;
    for(map<double, int>::iterator i = sell.begin(); i != sell.end(); i++){
        temp = i->second < buy[i->first] ? i->second : buy[i->first];
        if(temp >= now_max_amount){
            now_max_amount  = temp;
            now_max_price = i->first;
        }
    }
    printf("%.2lf %d\n",now_max_price,now_max_amount);
}
