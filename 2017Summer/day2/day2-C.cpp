/*
 * > File Name: day2-C.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月18日 星期二 08时33分41秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int table[101];
    for(int i = 1; i < 101; i++)
        table[i] = i*2;
    int n, m, pos,sum = 0;
    while(cin >> n >> m){
        for(pos = 1; n - pos >= m - 1; pos += m){
            for(int i = pos; i < pos + m; i++)
                sum += table[i];
            cout << sum/(float)m << " ";
            sum = 0;
        }
        if(pos <= n){
            for(int i = pos; i <= n; i++)
                sum += table[i];
            cout << sum/(float)(n - pos + 1) ;
            sum = 0;
        }
        cout << endl;
    }
}
