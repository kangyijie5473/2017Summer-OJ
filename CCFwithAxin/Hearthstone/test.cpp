/*
 * > File Name: test.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年10月29日 星期日 10时26分27秒
 */

#include <iostream>
#include <vector>
using namespace std;
int &fun(vector<int> &v)
{
    for(auto i : v)
        return i;
}
int main(void)
{
    vector<int> vec;
    vec.push_back(3);
    int &a = fun(vec);
    a = 2;
    cout << *vec.begin() << endl;
}

