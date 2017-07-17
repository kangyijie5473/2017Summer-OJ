/*
 * > File Name: day1-D.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月17日 星期一 07时50分29秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int n ,sum = 0, temp;
    while(cin >> n){
        if(!n)
            break;
        else{
            while(n--){
                cin >> temp;
                sum += temp;
            }
            cout << sum << endl;
            sum = 0 ;
        }
    }
}
