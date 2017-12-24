/*
 * > File Name: day1-F.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月17日 星期一 09时02分15秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int n, a, b, sum = 0;
    while(cin >> n){
        while(n--){
            cin >> a ;
            sum += a;
        }
        cout << sum << endl;
        sum = 0;
    }
}
