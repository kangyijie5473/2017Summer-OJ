class Solution {
public:
    /**
     * @param n: the max identifier of planet.
     * @param m: gold coins that Sven has.
     * @param limit: the max difference.
     * @param cost: the number of gold coins that reaching the planet j through the portal costs.
     * @return: return the number of ways he can reach the planet n through the portal.
     */
    long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
        
        // dfs is too slow
        // return dfs(n, 0, m, limit, cost);
        
        //dp
        long long dp[51][101] = {0};
        for(int i = 0; i <= m; i++)
            dp[n][i] = 1;
        
        for(int now = n-1; now >= 0; now--){
            for(int money = m; money > 0; money--)
                for(int j = now+1; j <= n && j <= now+limit; j++)
                    if(money >= cost[j])
                        dp[now][money] += dp[j][money-cost[j]];
        }
        return dp[0][m];
    }
    
    // long long dfs(const int &obj, const int &now, int money, const int &limit, const vector<int> &cost){
    //     if(now == obj)
    //         return 1;
    //     long long ret = 0;
    //     for(int i = now+1; i <= now+limit && i < cost.size(); i++){
    //         if(cost[i] <= money)
    //             ret += dfs(obj, i, money-cost[i], limit, cost);
    //     }
    //     return ret;
    // }
    
};