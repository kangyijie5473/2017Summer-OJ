class Solution {
public:
    /*
     * @param : String
     * @return: String
     */
    string convertPalindrome(string str) {
        int length = str.size();
        int max_sub_length;
        for(max_sub_length = length; max_sub_length >= 2; max_sub_length--){
            if(judge(max_sub_length,str))
                break;
        }
        string result;
        for(int i = length-1; i >= max_sub_length; i--)
            result.push_back(str[i]);  
        for(int i = 0; i < length; i++)
            result.push_back(str[i]);  
        return result;
    }
    int judge(int length,string &str){
        for(int i = 0,j = length -1; i <= j;i++,j--)
            if(str[i]!=str[j])
                return 0;
        return length;
    }

};