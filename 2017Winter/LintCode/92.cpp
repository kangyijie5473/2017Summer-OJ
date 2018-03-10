class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
    int length = A.size();
    vector< vector<int> > dp(length, vector<int>(m+1, 0) );

    sort(A.begin(), A.end());
    for(int i = 0; i < length; i++){
        for(int j = 0; j <= m; j++){
            if(j == 0 || (i == 0 && j-A[i] < 0))
                dp[i][j] = 0;
            else if(i == 0 && j-A[i] >= 0)
                dp[i][j] = A[i];
            else if(j-A[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]] + A[i]);
 
        }
    }
    return dp[length-1][m];
    }
};