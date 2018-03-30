#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int length = str.size();
	int index;
	for(int i = 0, j = 1; i < length && j < length; i = 0, j++){
		index = j;
		while(i < index && j < length && str[i] == str[j])
			i++,j++;
		if(i == index)
			break;
	}
	for(int i = index-1, j = length-1; i>=0 && j>=0; i--,j--)
		if(str[i] != str[j]){
			cout << "false";
			return 0;
		}
	if(index == length -1)
		cout << "false", index = 0;
	for(int i = 0; i < index; i++)
		cout << str[i];
	return 0;
}