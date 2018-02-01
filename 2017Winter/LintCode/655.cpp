class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        int cout = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result;
        int length = min(num1.size(), num2.size());
        for(int i = 0; i < length; i++){
            char n = num1[i] + num2[i] - '0' + cout;
            if(n > '9'){
                n = n -10;
                cout = 1;
            }else
                cout = 0;
            result.push_back(n);
        }

        if(num1.size() > length){
            for(int i = length; i < num1.size(); i++){
                char n = num1[i] + cout;
                if(n > '9'){
                    n = n -10;
                    cout = 1;
                }else
                    cout = 0;
                result.push_back(n);  
            }
        }
        if(num2.size() > length){
            for(int i = length; i < num2.size(); i++){
                char n = num2[i] + cout;
                if(n > '9'){
                    n = n -10;
                    cout = 1;
                }else
                    cout = 0;
                result.push_back(n);  
            }            
        }
        if(cout)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};