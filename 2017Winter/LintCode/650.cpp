class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        vector<vector<int>> result;
        if(root != NULL){
            int index = dfs(root, result);
            for(int i = result.size(); i <= index; i++)
                result.push_back(vector<int>());
            result[index].push_back(root->val);
            
        }
        return result;
    }
    int dfs(TreeNode *root, vector<vector<int>>& result)
    {
        if(root == NULL)
            return -1;
        int left = dfs(root->left, result);
        if(left != -1){
            for(int i = result.size(); i <= left; i++)
                result.push_back(vector<int>());
            result[left].push_back(root->left->val);

        }
        int right = dfs(root->right, result);
        if(right != -1){
            for(int i = result.size(); i <= right; i++)
                result.push_back(vector<int>());
            result[right].push_back(root->right->val);

        }
        return left > right ? left+1 : right+1;
    }
};