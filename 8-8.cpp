/*
 * > File Name: 8-8.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年08月08日 星期二 08时49分21秒
 */

#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    set<string> words;
    string line;
    while(cin >> line){
        auto head = line.begin();
        auto p = head;
        auto tail = line.end();
        while(p != tail + 1){
            if(*p <= 'Z' && *p >= 'A')
                *p = *p -'A' + 'a';
            if(*p > 'z' || *p < 'a'){
                words.insert(string(head, p));
                head = p+1;
            }
            p++;
        }
    }
    // zha zha OJ ge shi cuo wu 
    //for(auto const &it : words)
    //    cout << it << endl;
    auto t = words.end();
    t--;
    for(auto it = words.begin(); it != words.end(); it++){
        if(it != t)
            cout << *it << ' '<< endl;
        else
            cout << *it << endl;

    }
}
