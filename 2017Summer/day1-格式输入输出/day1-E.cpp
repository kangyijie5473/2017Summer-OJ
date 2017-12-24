/*
 * > File Name: day1-E.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月17日 星期一 07时50分29秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int n ,sum = 0, nn,temp;
    cin >> n;
    while(n--){
        cin  >> nn;       
        while(nn--){
            cin >> temp;
            sum += temp;
        }
        cout << sum << endl;
        sum = 0 ;
    }
}
