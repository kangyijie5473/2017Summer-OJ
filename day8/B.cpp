/*
 * > File Name: B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月25日 星期二 17时07分48秒
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(void)
{
    string a,b;
    char *res = new char [2000];
    int n,s ,temp,add, i = 0;
    cin >> n;
    s = n;
    getchar();
    while(n--){
        cin >> a >> b;
        auto p = a.end()-1;
        auto q = b.end()-1;
        auto a_head = a.begin()-1;
        auto b_head = b.begin()-1;
        add = 0;
        while(p != a_head && q != b_head){
            temp = *p + *q - '0' - '0' +add;
            add = temp /10;
            temp %= 10;
            res[i++] = temp+'0';
            p--;
            q--;
        }
        if(a.size() == b.size() && add)
            res[i++] = add + '0';
        if(a.size() > b.size()){
            while(p != a_head){
                temp = *p - '0' + add;
                add  = temp/10;
                temp %= 10;
                res[i++] = temp +'0';
                p--;
            }
            if(add)
                res[i++] = add + '0';
        }
        if(b.size() > a.size()){
            while(q != b_head){
                temp = *q - '0' + add;
                add = temp / 10;
                temp %= 10;
                res[i++] = temp + '0';
                q--;
            }
            if(add)
                res[i++] = add + '0';
        }
        
        cout << "Case " << s - n << ':'  << endl;
        cout << a << " + " << b << " = ";
        for(int j = i-1; j >= 0; j--)
            cout << res[j];
        cout << endl ;
        if(n)
            cout << endl;
        i = 0;
    }
    delete res;
}
