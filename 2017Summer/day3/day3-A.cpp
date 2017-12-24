/*
 * > File Name: day3-A.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月19日 星期三 06时57分42秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int cow = 1,one_year = 0,two_year = 0,three_year = 0;
    int year = 2;
    long long number[55];
    number[1] = 1;
    while(year != 55){
        cow += three_year;
        three_year = two_year;
        two_year = one_year;
        one_year = cow;
        number[year] = cow + one_year + two_year + three_year;
        year++;
    }
    int n;
    while(cin >> n){
        if(!n)
            break;
        else 
            cout << number[n] << endl;
    }


}
