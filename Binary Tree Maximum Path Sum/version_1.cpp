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
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int ma =0;
        dfs(root, ma);
        if(ma ==0)
        {
            ma = 0x80000000;
            dfs_find_min(root, ma);
        }
        return ma;
    }
    void dfs_find_min(TreeNode *root, int &ma)
    {
        if(!root)
            return;
        if(root->val> ma)
            ma = root->val;
        dfs_find_min(root->left, ma);
        dfs_find_min(root->right, ma);
    }
        
    int dfs(TreeNode* root, int & ma)
    {
        if(!root)
            return 0;
        int left, right;
        left = dfs(root->left, ma);
        right = dfs(root->right, ma);
        int right_path = 0;
        int right_max =0;
        if(root->val >0)
        {
            right_max = max(left, right) +root->val;
            right_path = left+right+root->val;
        }
        else
        {
            right_max = max(left, right)+root->val;
            right_max = max(right_max, 0);
            right_path = max(left, right);
            right_path = max(right_path, left+right+root->val);
        }
        
        if(right_path>ma)
            ma = right_path;
        return right_max;
    }
};