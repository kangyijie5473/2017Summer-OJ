/*
 * > File Name: day1-H.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月17日 星期一 09时06分28秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int n, sum = 0, temp, nn;
    cin >> n;
    while(n--){
        cin >> nn;
        while(nn--){
            cin >> temp;
            sum += temp;
        }
        cout << sum << endl;
        if(n)
            cout << endl;
        sum = 0;
    }
}
