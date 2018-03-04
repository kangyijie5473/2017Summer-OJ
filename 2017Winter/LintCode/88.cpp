#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};
 
class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B){
        // write your code here
        vector<TreeNode*> A_root, B_root;
        dfs(root, A, A_root);
        dfs(root, B, B_root);

        for(auto i = A_root.rbegin(); i != A_root.rend(); i++){
            for(auto j = B_root.rbegin(); j != B_root.rend(); j++)
                if(*i == *j)
                    return *i;
        }
        return NULL;
    }
    int dfs(TreeNode *root, TreeNode *now, vector<TreeNode*> &pre){
        if(!root){
            return 0;
        }
        pre.push_back(root);
        if(root == now)
            return 1;

        if(dfs(root->left, now, pre))
            return 1;
        if(dfs(root->right, now, pre))
            return 1;
        pre.pop_back();
        return 0;
        
    }
};