#include <bits/stdc++.h>
#include <cassert>
using namespace std;

class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here
        if (s.size() == 0)
            return true;
    	vector<int> dp(s.size(), 0);
    	dp[0] = dict.find(s.substr(0, 1)) == dict.end() ? 0 : 1;
    	int length = s.size();
    	for (int i = 0; i < length; i++) {
            // it might reduce time but i can't fix bug
            
            // for (auto word : dict) {
            //     int start = i - (int)word.size();
            //     if (start >= 0 && dp[start] && word == s.substr(start, word.size())) {
            //         dp[i] = 1;
            //         break;
            //     }

            // }
    		for (int j = 0; j <= i; j++) {
    			string sub = s.substr(j, i - j + 1);
    			if ((j == 0 || dp[j - 1]) && dict.find(sub) != dict.end()) {
                    cout << "i:" << i << "j:" << j << ' ' << sub << endl;
    				dp[i] = 1;
                    //old = i;
    				break;
    			}
    		}
    	}
        for (int i = 0 ;i < dp.size(); i++)
            cout << "index:" << i << dp[i] << endl;
    	if (dp[length - 1] == 1)
    		return true;
    	else 
    		return false;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	string str = "lintcode";
	unordered_set<string> dict = {"lint", "code"};

	cout << s.wordBreak(str, dict) << endl;
	return 0;
}