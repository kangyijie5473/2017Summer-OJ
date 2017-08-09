/*
 * > File Name: 8-9.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年08月09日 星期三 09时04分17秒
 */

#include <iostream>
#include <list>
using namespace std;
int main(void)
{
    cin.sync_with_stdio(false);
    list<string> res;
    string line;
    bool end = false;
    bool home = false;
    while(cin >> line){
        auto it = line.begin();
        auto head = it;
        auto tail = line.end();
        while(1){
            
            while(it != tail && *it != '[' && *it != ']' )
                it++;
            if(home)
                res.push_front(std::move(string(head, it)));
            else
                res.push_back(std::move(string(head, it)));
            home = end = false;
            if(it == tail){
                for(auto i : res)
                    cout << i ;
                cout << endl;
                res.clear();
                break;
            }
            if(*it == '[')
                home = true;
            else 
                end = true;
            it++;
            head = it;
        }

    }
}
