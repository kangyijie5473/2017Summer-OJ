#include <bits/stdc++.h>
using namespace std;
static map<char, int> priority_map = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}};

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    bool isGreaterPriority(const char p, const char q)
    {
    	if (priority_map[p] > priority_map[q])
    		return true;
    	else
    		return false;
    }
    bool isGreaterOrEqualPriority(const char p, const char q)
    {
    	if (priority_map[p] >= priority_map[q])
    		return true;
    	else
    		return false;
    }
	void popStack(stack<char> &st, vector<string> &result)
	{
		while (st.empty() == false) {
			string temp;
			temp += st.top();
			st.pop();
			result.push_back(temp);
		}
	}
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        stack<char> st;
        vector<string> result;
        int length = expression.size();
        for (int i = 0; i < length; i++) {
        	if ((expression[i][0] >= '0' && expression[i][0] <= '9') || 
        		(expression[i][0] == '-' && expression[i].size() > 1))
        		result.push_back(expression[i]);
        	else {
        		if (expression[i][0] != ')') {
        			if (st.empty() == true || isGreaterPriority(expression[i][0], st.top())) {
        				//cout << "direct push " << expression[i][0] << endl;
        				st.push(expression[i][0]);
        			}
        			else {
        				while (st.empty() == false && st.top() != '(' && isGreaterOrEqualPriority(st.top(), expression[i][0])) {
        					string temp;
							temp += st.top();
							st.pop();
							//cout << "push result" << temp << endl;
							result.push_back(temp);				
        				}
        				//cout << "push" << expression[i][0] << endl; 
        				st.push(expression[i][0]);       				
        			}

        		} else {
        			while (st.empty() == false && st.top() != '(') {
    					string temp;
						temp += st.top();
						st.pop();
						result.push_back(temp);	        				
        			}
        			st.pop();
        		}
        		// popStack(st, result);
        		// st.push(expression[i][0]);
        	}
        }
        popStack(st, result);
        return result;
    }
    int test()
    {
    	cout << isGreaterPriority('-', '*') << endl;
    }
};
int main(int argc, char const *argv[])
{
	Solution s;
	//s.test();
	vector<string> input = {"2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"};
	vector<string> res = s.convertToRPN(input);
	for (auto i : res)
		cout << i << endl;
	return 0;
}