#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
string countWord(const string &str)
{

	map<string, int> words;
	for(auto i = str.begin(); i != str.end(); i++){
		if(*i != ' '){
			string word;
			for(; i != str.end() && *i != ' '; i++){
				word.push_back(*i);
			}
			words[word]++;
		}
		if(i == str.end())
			break;
	}
	string result;
	if(str.size() == 0)
		return result;
	int max = 0;
	for(auto i : words){
		if(i.second > max){
			result = i.first;
			max = i.second;
		}

	}
	return result;

}
int main()
{
	string a("cc a aa bb aa aaa");
	string b("");
	cout << countWord(b);
}