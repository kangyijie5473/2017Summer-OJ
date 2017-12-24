/*
 * > File Name: 8-10.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年08月10日 星期四 08时08分24秒
 */

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(void)
{
    int n ;
    int len;
    stack<char> res;
    char *p;
    char line[1000] = {0};
    string temp;
    cin >> n;
    getchar();
    while(n--){
        getline(cin,temp);
        memcpy(line, temp.c_str(), temp.size());
        if(strlen(line) == 0){
            cout << "Yes" << endl;
            continue;
        }
        p = &line[0];
        while(*p != '\0'){
            if(!res.empty()){
                if((res.top() == '[' && *p == ']') ||
                   (res.top() == '(' && *p == ')') )
                    res.pop();
                else
                    res.push(*p);
            }else 
                    res.push(*p);
            p++;
        }
        if(res.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        while(!res.empty())
            res.pop();
    }
}
