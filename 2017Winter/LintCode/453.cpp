/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: a TreeNode, the root of the binary tree
     * @return: 
     */
    void flatten(TreeNode * root) {
        // write your code here
        if(!root)
            return ;
        if(root->left){
            TreeNode *temp = root->left;
            while(temp->right)
                temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
                
        }
        flatten(root->right);
    }
};