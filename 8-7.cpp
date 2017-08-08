/*
 * > File Name: 8-7.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年08月07日 星期一 17时23分05秒
 */

#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    map<string,int> ball;
    int n;
    while(1){
        cin >> n;
        getchar();
        if(!n)
            break;
        while(n--){
            string color;
            cin >> color;
            if(ball.find(color) == ball.end())
                ball.insert(make_pair(color,1));
            else
                ball[color]++;
        }
        string res;
        int max = 0;
        for(const auto &it : ball){
            if(it.second > max){
                res = it.first;
                max = it.second;
            }
        }
        ball.clear();
        cout << res << endl;
    }
}
