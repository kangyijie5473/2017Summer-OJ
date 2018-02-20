class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        string n;
        while(num){
            n.push_back(num%10);
            num /= 10;
        }
        int length = n.size();
        if(length == 1)
            return true;
        for(int i = 0, j = length - 1; i <= j; i++,j--){
            if(n[i] != n[j])
                return false;
        }
        return true;
    }
};  