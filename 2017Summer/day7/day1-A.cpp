/*
 * > File Name: day1-A.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月24日 星期一 08时05分32秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    string str;
    cin >> str;
    int num[27] = {0};
    int word[7];
    for(auto i = str.begin(); i < str.end(); ++i){
        if(*i >= 'a' && *i <= 'z'){
            num[*i - 'a']++;
        }
        if(*i == 'B')
            num[26]++;
    }
    if(num['b'-'a'] == 1);
    else if(num['b'-'a'] % 2 == 1)
        num['b'-'a'] -= 1;
    
    if(num[26] == 1);
    else if(num[26] % 2 == 1)
        num[26] -= 1;

    if(num['u' - 'a'] == 1);
    else if(num['u'-'a'] % 2 == 1)
        num['u'-'a'] -= 1;
    if(num['a' - 'a'] == 1);
    else if(num['a'-'a'] % 2 == 1)
        num['a'-'a'] -= 1;
    word[0] = num[26];
    word[1] = num['u'-'a'];
    word[2] = num['l'-'a'];
    word[3] = num['b'-'a'];
    word[4] = num['a'-'a'];
    word[5] = num['s'-'a'];
    word[6] = num['r'-'a'];
    int min = 100000;
    for(int i = 0; i < 7; i++){
        if(word[i] < min)
            min = word[i];
        //cout << word[i] << ' ';
    }
    //cout << endl;
    cout << min << endl;
}
