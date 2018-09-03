#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    static int toInt(const string &str)
	{
		int res = 0;
		int power = 1;
		for (auto i = str.rbegin(); i != str.rend(); i++) {
			res += (*i - '0') * power;
			power *= 10;
		}
		return res;
	}
    int calculate(string &s) {
        // Write your code here
        vector<string> str;
        stack<char> st;
        int length = s.size();
       	for (int i = 0; i < length; i++) {
       		if (s[i] == ' ')
       			continue;
       		if (s[i] >= '0' && s[i] <= '9'){
       			string temp;
       			while(s[i] >= '0' && s[i] <= '9') {
       				temp += s[i];
       				i++;
       			}
       			str.push_back(temp);
       			i--;
       		} else if (s[i] == '+' || s[i] == '-' ) {
          		while (st.empty() == false && st.top() != '(') {
       				string temp;
       				temp += st.top();
       				str.push_back(temp);
       				st.pop();          			
          		}
          		st.push(s[i]);
    		} else if (s[i] == '(') {
    			st.push(s[i]);

       		} else if (s[i] == ')') {
       			while(st.top() != '(') {
       				string temp;
       				temp += st.top();
       				str.push_back(temp);
       				st.pop();
       			}
       			st.pop();
       		}
       	}

       	while (st.empty() == false) {
       		string temp;
       		temp += st.top();
       		str.push_back(temp);
       		st.pop();
       	}
       	for (auto i : str)
       		cout << i << endl;
       	stack<int> num_st;
       	stack<char> op_st;
       	for (auto i : str) {
       		if (i[0] >= '0' && i[0] <= '9') {
       			num_st.push(toInt(i));
       		}
       		else {
   				int n1 = num_st.top();
   				num_st.pop();
   				int n2 = num_st.top();
   				num_st.pop();
   				if (i[0] == '+')
   					n2 += n1;
   				else 
   					n2 -= n1;
   				//cout << "temp" << i[0] << n2 << endl;
   				num_st.push(n2);

       		}
       	}
       	return num_st.top();
    }
};
int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string str = "(1+(4+5+2)-3)+(6+8)";
	cout << "result is " << s.calculate(str) << endl;
	return 0;
}