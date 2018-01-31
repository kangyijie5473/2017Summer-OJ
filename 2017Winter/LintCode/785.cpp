// demo
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m = 3;
int n = 3;
int table[3][3];

int result(int i, int j, vector<vector<int>> &nums){
        if(table[i][j] != 0)
            return table[i][j];
        if(i == m - 1 && j == 0)
            return table[i][j] = nums[i][j];
        if(i == m -1)
            return table[i][j] = nums[i][j] + result(i, j-1, nums);
        if(j == 0)
            return table[i][j] = nums[i][j] + result(i+1, j, nums);
        return table[i][j] = nums[i][j] + max(result(i, j-1, nums), result(i+1, j, nums));
  }
int main()
{
	vector<vector<int>> nums;
	freopen("785-in", "r", stdin);
	for(int i = 0; i < m; i++){
		vector<int> temp;
		nums.push_back(temp);
        for(int j = 0; j < n;j++){
            nums[i].push_back(0) ;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n;j++){
            cin >> nums[i][j] ;
        }
    }
    cout << result(0, n-1, nums);
}

// answer
class Solution {
public:
    /**
     * @param nums: the n x m grid
     * @return: the maximum weighted sum
     */
     int m;
     int n;
    int maxWeight(vector<vector<int>> &nums) {
        m = n = nums.size();
        vector<vector<int>> table;

        for(int i = 0; i < m; i++){
            vector<int> temp;
            table.push_back(temp);
            for(int j = 0; j < n;j++){
                table[i].push_back(0) ;
            }
        }

        return result(0, n-1, nums, table);
    }
    int result(int i, int j, vector<vector<int>> &nums,  vector<vector<int>> &table){
        if(table[i][j] != 0)
            return table[i][j];
        if(i == m - 1 && j == 0)
            return table[i][j] = nums[i][j];
        if(i == m -1)
            return table[i][j] = nums[i][j] + result(i, j-1, nums,table);
        if(j == 0)
            return table[i][j] = nums[i][j] + result(i+1, j, nums,table);
        return table[i][j] = nums[i][j] + max(result(i, j-1, nums,table), result(i+1, j, nums,table));
    }
};