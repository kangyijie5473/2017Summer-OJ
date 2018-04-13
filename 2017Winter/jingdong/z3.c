#include <bits/stdc++.h>
using namespace std;
bool judge(string &s)
{
	int c =0;
	int length = s.size();
	for(int i = 0; i < length; i++){
		if(s[i] == '(')
			c++;
		else
			c--;
		if(c < 0)
			return false;
	}
	if(c != 0)
		return false;
	else
		return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s.size() == 2){
			if(s[0] == '('){
				cout << "No" << endl;
			}else
				cout << "Yes" << endl;
			continue;
		}
		if(judge(s)){
			cout << "yes" << endl;
			continue;
		}
		int l, r, c = 0;
		int length = s.size();
		for(int i = 0; i < length; i++){
			if(s[i] == '(')
				c++;
			else
				c--;
			if(c < 0){
				l = i;
				break;
			}
		}
		for(int i = length - 1; i >= 0; i--){
			if(s[i] == ')')
				c++;
			else
				c--;
			if(c < 0){
				r = i;
				break;
			}
		}
		char temp = s[l];
		s[l] = s[r];
		s[r] = temp;
		if(judge(s)){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}

	}
	return 0;
}