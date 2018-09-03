#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int toInt(const string &str)
    {
    	int res = 0;
    	int power = 1;
    	for (auto i = str.rbegin(); i != str.rend(); i++) {
    		if (*i == '-') {
    			res *= -1;
    			continue;
    		}

    		res += (*i - '0') * power;
    		power *= 10;
    	}
    	return res;
    }
    int evalRPN(vector<string> &tokens) {
        // write your code here
        stack<int> num_st;
        for (auto i : tokens) {
        	if ((i[0] >= '0' && i[0] <= '9') || (i.size() > 1 && i[0] == '-'))
        		num_st.push(toInt(i));
        	else {
        		int n1 = num_st.top();
        		num_st.pop();
        		int n2 = num_st.top();
        		num_st.pop();
        		if (i[0] == '+') 
        			n2 += n1;
        		else if (i[0] == '-')
        			n2 -= n1;
        		else if (i[0] == '*')
        			n2 *= n1;
        		else if (i[0] == '/')
        			n2 /= n1;
        		num_st.push(n2);
        	}
        }
        return num_st.top();
    }

};
int main(int argc, char const *argv[])
{
	Solution s;
	vector<string> tokens = {"4", "13", "5", "/", "+"};
	cout << s.evalRPN(tokens) << endl;
	return 0;
}