class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    
    // recursize
    int Max = 0;
    int maxDepth(TreeNode *root) {
        if(!root)
            return 0;
        print(root,1);
        return Max;
    }
    void print(TreeNode *root, int dep){
        if(!root)
            return ;
        if(dep > Max)
            Max = dep;
        print(root->left, dep+1);
        print(root->right, dep+1);
        return ;
    }
    
    
    // no-recursize
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> q;
        if(!root)
            return 0;
        int depth = 0 ;
        q.push(root);
        while(!q.empty()){
            int cur = 0;
            int last = q.size();
            while(cur < last){
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                cur++;
            }
            depth++;
        }
        return depth;
    }
};