/*
 * > File Name: day5-A.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月21日 星期五 08时22分28秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    double ave;
    double temp;
    double sum = 0;
    for(int i = 0; i < 12; ++i){
        cin >> temp;
        sum += temp;
    }    
    cout << "$" << sum/12.00 << endl;
}

