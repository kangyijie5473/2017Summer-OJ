/*
 * > File Name: day1-C.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月17日 星期一 07时43分30秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    int a,b;
    while(cin >> a >> b){
        if(a || b)
            cout << a + b << endl;
        else 
            break;
    }
}
