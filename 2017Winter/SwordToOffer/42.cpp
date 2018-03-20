#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
using namespace std;
string func(string str)
{
	reverse(str.begin(), str.end());
	cout << str << endl;
	for(auto i = str.begin(); i != str.end(); i++){
		if(*i == ' '){
			continue;
		}else{
			auto p = i;
			while(*i != ' ' && i != str.end())
			 	i++;
			 reverse(p, i);
		}
		if(i == str.end())
			break;
	}
	return str;
}
int main()
{
	string a("I love who") ;
	cout << func(a) << endl;
}