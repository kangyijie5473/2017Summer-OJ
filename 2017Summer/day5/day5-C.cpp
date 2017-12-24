/*
 * > File Name: day5-C.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月21日 星期五 08时15分37秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    long long mian[31];
    int n ,num;
    long long last = 3;
    for(int i = 1; i < 31; i++){
        last -= 1;
        last *= 2;
        mian[i] = last;
    }
    cin >> n;
    while(n--){
        cin >> num;
        cout << mian[num] << endl;
    }
}
