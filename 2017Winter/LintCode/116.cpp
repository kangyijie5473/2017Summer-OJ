class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        
        //dp
        
        // int dp[1000] = {0};
        // dp[0] = A[0];
        // int length = A.size();
        // for(int i = 1; i < length; i++){
        //     if(dp[i-1] == 0)
        //         return false;
        //     dp[i] = max(dp[i-1]-1, A[i]);
        // }
        // return true;
        
        //greedy
        
        //special case
        if(A.size() == 1)
            return true;
        if(A[0] == 0)
            return false;
            
        int Max = A[0];
        int length = A.size();
        for(int i = 0; i < length-1; i++){
            if(i > Max)
                return false;
            Max = max(A[i]+i, Max);
            if(Max >= length-1)
                return true;
        }
        return false;

    }
};