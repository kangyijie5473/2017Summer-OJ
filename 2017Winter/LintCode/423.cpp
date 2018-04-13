class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        if(s.size() == 0 || s.size()%2 != 0)
            return false;
        int length = s.size();
        stack<char> st;
        for(int i = 0; i < length; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))
                    st.pop();
                else
                    return false;
            }
                
        }
        if(st.empty())
            return true;
        else
            return false;

    }
};