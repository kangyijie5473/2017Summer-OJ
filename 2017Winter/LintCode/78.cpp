class Solution {
public:
    /*
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        
        string result;
        if(strs.size() == 0)
            return result;
        for(int i = 0;;i++){
            char now = '\0'; 
            for(auto j = strs.begin(); j != strs.end(); j++){
                if(i == j->length())
                    return result;
                if(j == strs.begin())
                    now = (*j)[i];
                if(now != (*j)[i])
                    return result;
                
            }
            result.push_back(now);
        }
    }
};