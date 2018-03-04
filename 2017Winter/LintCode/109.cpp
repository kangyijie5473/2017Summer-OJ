class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> table;
        for(int i = 0; i < triangle.size(); i++){
            vector<int> t;
            for(int j = 0; j < triangle[i].size(); j++)
                t.push_back(0);
            table.push_back(t);
        }
        return dp(triangle, 0,0,table);
    }
    int dp(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &table){
        if(table[r][c] != 0)
            return table[r][c];
        if(r == triangle.size()-1)
            return triangle[r][c];
        return table[r][c] = min(dp(triangle, r+1, c, table), dp(triangle, r+1, c+1, table))+triangle[r][c];
        
    }
};