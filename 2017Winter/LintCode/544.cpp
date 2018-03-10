class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */

    vector<int> topk(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        int length = nums.size();
        for(int i = 0; i < k; i++)
            q.push(nums[i]);
        for(int i = k; i < length; i++){
            if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        vector<int> result;
        for(int i = 0; i < k;i++){
            int t = q.top();
            q.pop();
            result.push_back(t);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};