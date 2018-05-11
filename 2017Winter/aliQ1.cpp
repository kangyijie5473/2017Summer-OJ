#include <bits/stdc++.h>
using namespace std;
string add(string &n1, string &n2)
{
	string result;
	string &long_n  = n1.size() >= n2.size() ? n1 : n2;
	string &short_n = n1.size() < n2.size() ? n1 : n2;
	reverse(long_n.begin(), long_n.end());
	reverse(short_n.begin(), short_n.end());
	int c = 0;
	for(int i = 0; i < short_n.size(); i++){
		if(long_n[i] == '.'){
			result.push_back('.');
			continue;
		}
		result.push_back((long_n[i] + short_n[i] - '0' - '0' + c)%10+'0');
		c = (long_n[i] + short_n[i] - '0' - '0' + c)/10;			
	}
	for(int i = short_n.size(); i < long_n.size(); i++){
		result.push_back((long_n[i] - '0' + c)%10 + '0');
		c = (long_n[i] - '0' + c)/10;
	}
	if(c != 0)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}
bool getResult()
{
	string str;
	cin >> str;
	if(str.find('+') == string::npos)
		return false;
	auto m = str.begin();
	for(auto i = str.begin(); i != str.end(); i++){
		if(!((*i >= '0' && *i <= '9') || (*i == '+') || *i == '.'))
			return false;
		if(*i == '+')
			m = i;
	}
	string n1(str.begin(), m), n2(m+1, str.end());
	bool f1 = n1.find('.') != string::npos;
	bool f2 = n2.find('.') != string::npos;
	string result;

	if(f1 == true && f2 == true){
		//like"123.2+230.2"
		int len = n1.size() - n1.find('.') - (n2.size() - n2.find('.'));
		if(len > 0){
			for(int i = 0; i < len; i++)
				n2.push_back('0');
		}else if(len < 0){
			len *= -1;
			for(int i = 0;i < len; i++)
				n1.push_back('0');
		}
		result = add(n1, n2);
	}else if(f1 == true || f2 == true){
		//like "123+200.1"
		if(f1 == true){
			int l = n1.size() - n1.find('.');
			n2.push_back('.');
			for(int i = 0; i < l-1; i++)
				n2.push_back('0');
		}else{
			int l = n2.size() - n2.find('.');
			n1.push_back('.');
			for(int i = 0; i < l-1; i++)
				n1.push_back('0');
		}
		result = add(n1, n2);
	}else{
		// not include '.' like "123+324"
		result = add(n1,n2);
	}
	cout << result << endl;
	return true;
}
int main()
{
	getResult();
}