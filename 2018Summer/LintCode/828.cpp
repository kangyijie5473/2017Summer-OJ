#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param pattern: a string, denote pattern string
     * @param teststr: a string, denote matching string
     * @return: an boolean, denote whether the pattern string and the matching string match or not
     */
    bool wordPattern(string &pattern, string &teststr) {
        // write your code here
        vector<string> v;
        int length = teststr.size();
        auto e = teststr.end();
        auto start = teststr.begin();
        for (auto i = teststr.begin(); i != e ; i++) {
        	while (i != e && *i != ' ')
        		i++;
        	string s(start, i);
          	v.push_back(s);

        	if (i == e){
        		break;
        	}
        	start = i+1;
        }
        // for (auto i : v) 
        // 	cout << i << endl;
        map<char, string> pattern_map;
        map<string, char> pattern_map_r;
        length = pattern.size();
        for (int i = 0; i < length; i++) {
        	if (pattern_map.find(pattern[i]) == pattern_map.end()) {
        		pattern_map.insert(make_pair(pattern[i], v[i]));
        		pattern_map_r.insert(make_pair(v[i], pattern[i]));
        	}
        	else if (pattern_map[pattern[i]] != v[i] || pattern_map_r[v[i]] != pattern[i]) {
        		//cout << pattern_map[pattern[i]] << "   " << v[i] << " " << i << endl;
        		return false;
        	}
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	string pattern = "abba";
	string teststr = "dog dog dog dog";
	cout << s.wordPattern(pattern, teststr) << endl;
	return 0;
}