class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        int length = nums.size();
        if(length == 0)
            return 0;
        vector<int> dp(length, 1);
        for(int i = 0; i < length; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        sort(dp.begin(), dp.end());
        return *(dp.end()-1);
    }
};