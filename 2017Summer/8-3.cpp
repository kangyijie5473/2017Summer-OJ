/*
 * > File Name: 8-3.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年08月03日 星期四 08时17分44秒
 */

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string a ,b;
    while(cin >> a >> b){
        auto it_a = a.begin();
        auto it_b = b.begin();
        while(*it_a == '0')
            it_a++;
        while(*it_b == '0')
            it_b++;
        while(*it_a == *it_b && it_a != a.end() && it_b != b.end()){
            it_a++;
            it_b++;
        }
        if(it_a == a.end() && it_b == b.end()){
            cout << "YES" << endl;
            continue;
        }

        if(*it_a != *it_b && it_a != a.end() && it_b != b.end()){
            cout << "NO" << endl;
            continue;
        }

        if(it_a != a.end()){
            if(*it_a == '.')
                it_a++;
            while(*it_a == '0' && it_a != a.end())
                it_a++;
            if(it_a == a.end()){
                cout << "YES" << endl;
                continue;
            }else {
                cout << "NO" << endl;
                continue;
            }
        }
        else if(it_b != b.end()){
            if(*it_b == '.')
                it_b++;
             while(*it_b == '0' && it_b != b.end())
                it_b++;
            if(it_b == b.end()){
                cout << "YES" << endl;
                continue;
            }else {
                cout << "NO" << endl;
                continue;
            }
            } 
    }
}
