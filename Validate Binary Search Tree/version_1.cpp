/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        int mi, ma;
        return dfs(root, mi, ma);
    }
    bool dfs(TreeNode * root , int &mi, int &ma)
    {
        int new_min;
        int new_max;
        if(root->left)
        {
            
            if(root->val <= root->left->val)
                return false;
            if(!dfs(root->left, new_min, new_max))
                return false;
            if(root->val <= new_max)
                return false;
            mi = new_min;
            
        }
        else
            mi = root->val;
        
        if(root->right)
        {
            if(root->val >= root->right->val)
                return false;
            if(!dfs(root->right, new_min, new_max))
                return false;
            if(root->val >= new_min)
                return false;
            ma = new_max;
        }
        else
            ma = root->val;
        return true;
        
    }
};