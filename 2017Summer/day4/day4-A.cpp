/*
 * > File Name: day4-A.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月20日 星期四 08时02分38秒
 */

#include <iostream>
#include <cmath>
using namespace std;
int main(void)
{
    int m ,n ;
    int flag = 0;
    int a,b,c;
    int num[10];
    int k = 0;
    while(cin >> m >> n){
        for(int i = m; i <= n; ++i){
            a = i/100;
            b = i/10%10;
            c = i%10;
            if(pow(a,3)+pow(b,3)+pow(c,3) == i){
               // cout << i << ' ';
                num[k++] = i;
                flag = 1;
            }
        }
        if(!flag)
            cout << "no" << endl;
        else {
            for(int i = 0; i < k ;i++)
            {
                cout << num[i];
                if(i+1 != k)
                    cout << ' ';
            }
            cout << endl; 
            k = 0;
        }
        flag = 0;
    }
}
