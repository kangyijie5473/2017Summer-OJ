/*
 * > File Name: day7-B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月24日 星期一 21时59分19秒
 */

#include <iostream>
using namespace std;
#define Swap(a,b) {if(a < b) {a = a+b; b = a - b; a = a -b;}}
unsigned long long  GetGCD(unsigned long long  a, unsigned long long  b) 
{
        Swap(a,b);
        unsigned long long  c = a % b; 
        if(!c)
            return b;
    while(c){
                a = b;
                b = c;
                c = a % b;
            
    }
        return b;

}
#define GetCMP(a,b)  b = a * b / GetGCD(a,b); 

int main(void)
{
    int n;
    cin >> n;
    getchar();
    unsigned long long a,b,c,d;
    while(n--){
        scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
        unsigned long long e =a*d;
        unsigned long long f =b*c;
        unsigned long long  gcd = GetGCD(e,f);
        cout << gcd << endl;
        if(b*d %gcd){
            cout << b*d / gcd << endl;
        }else
            cout << b*d << "/" << gcd << endl;
    }
}
