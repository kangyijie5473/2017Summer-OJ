class Solution {
public:
    /*
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int length;
    int r_length;
    int numIslands(vector<vector<bool>> &grid) {

        length = grid.size();
        if(!length)
            return 0;
        r_length = grid[0].size();

        int count = 0;
        for(int i = 0; i < length; i++){
            for(int j = 0; j < r_length; j++){
                if(grid[i][j] == true){
                    grid[i][j] = false;
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }

    int dfs(int i, int j, vector<vector<bool>> &grid){
        if(i - 1>=0 && grid[i-1][j] == true){
            grid[i-1][j] = false;
            dfs(i-1, j, grid);
        }
        if(j - 1>=0 && grid[i][j-1] == true){
            grid[i][j-1] = false;
            dfs(i, j-1, grid);
        }            
        if(i + 1< length && grid[i+1][j] == true){
            grid[i+1][j] = false;
            dfs(i+1, j, grid);
        }         
        if(j + 1 < r_length && grid[i][j+1] == true){
            grid[i][j+1] = false;
            dfs(i, j+1, grid);
        }
        return 0;
    }
};