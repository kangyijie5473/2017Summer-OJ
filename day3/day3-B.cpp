/*
 * > File Name: day3-B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月19日 星期三 07时20分17秒
 */

#include <iostream>
#include <cstdio>
using namespace std;
#define Swap(a,b) {if(a < b) {a = a+b; b = a - b; a = a -b;}}
#define GetCMP(a,b) { b = a * b / GetGCD(a,b);}
int GetGCD(int a, int b) 
{
    Swap(a,b);
    unsigned int c = a % b; 
    if(!c)
        return b;
    while(c){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int main(void)
{
    unsigned int num[200];
    int n;
    while(cin >> n){
        for(int i = 0; i < n; ++i)
            scanf("%ud",&num[i]);
        for(int i = 0; i < n - 1; ++i)
            GetCMP(num[i],num[i+1]);
        cout << num[n-1] << endl;
    }
}
