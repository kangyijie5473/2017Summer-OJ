/*
 * > File Name: day5-B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月21日 星期五 07时59分11秒
 */

#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
    int n;
    string str;
    cin >> n;
    getchar();
    while(n--){
        getline(cin,str);
        cout << str << endl;
        auto p = str.begin();
        auto q = str.end()-1; 
        while(1){
            if(*p != *q){
                cout << "no" << endl;
                break;
            }
            if(p > q || q == p){
                cout << "yes" << endl;
                break;
            }
            p++;
            q--;
        }
    }
}
