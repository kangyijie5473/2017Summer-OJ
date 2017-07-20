/*
 * > File Name: day4-B.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年07月20日 星期四 08时19分30秒
 */

#include <iostream>
using namespace std;
int main(void)
{
    string line;
    int t;
    cin >> t ;
    getchar();
    while(t--){
        getline(cin, line);
        auto p = line.begin();
        auto q = p;
        while(p != line.end()){
            while(*p != ' ' && p != line.end())
                p++;
            for(auto i = p -1; i >= q; i--)
                cout << *i;
            
            if(p == line.end())
                break;
	    cout << ' ';
            p++;
            q = p;
        }   
        cout << endl;
    }
}
