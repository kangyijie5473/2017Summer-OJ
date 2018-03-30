#include <bits/stdc++.h>
using namespace std;
string getRawstr(int n)
{
	string result;
	for(int i = 0; i < n; i++){
		result.push_back('(');
		result.push_back(')');
	}
	return result;
}
bool inline judge(string &str)
{
	int c = 0;
	int length = str.size();
	for(int i = 0; i < length; i++){
		if(str[i] == '(')
			c++;
		else
			c--;
		if(c < 0)
			return false;
	}
	if(c != 0)
		return false;
	return true;
}
void Swap(string &s, int i , int j)
{
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
void dfs(set<string> &result, string &s, int index)
{
	if(judge(s))
		result.insert(s);
	int length = s.size();
	for(int i = index; i < length; i++){
		Swap(s,index, i);
		dfs(result, s, index+1);
		Swap(s,index, i);
	}
	return ;
}
int main()
{
	set<string> result;
	int n;
	cin >> n;
	if(n == 1){
		cout << "()";
		return 0;
	}
	string raw_str = getRawstr(n);
	dfs(result, raw_str, 0);
	// cout << raw_str << endl;
	// string s1("(()))");
	// string s2("(())");
	// cout << judge(s1) << endl;
	// result.insert(s1);
	// result.insert(s2);



	int c = 1;
	int length = result.size();
	for(auto i = result.begin(); i != result.end(); i++,c++){
		if(c == length){
			cout << *i;
		}
		else{
			cout << *i << ',';
		}
	}
	return 0;
}