/*
 * > File Name: day3-C.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月19日 星期三 07时09分52秒
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(void)
{
    string str;
    int n;
    int num = 0;
    scanf("%d\n",&n);
    while(n--){
        getline(cin,str);
        /*针对GB2312的两字节编码*/
        for(auto const &it : str){
            if(it &0x80)
                num++;
        }
        cout << num / 2 << endl;
        num = 0;
        /*针对UTF8的三字节编码*/
        /*
        for(auto it = str.begin(); it < str.end() - 2; ++it){
            if(*it & 0x80 && *(it+1) & 0x80 && *(it+2) & 0x80){
                num++;
                it += 2;
                continue;
            }
        }
        cout  << num << endl;
        num = 0;
        */
    }
}
