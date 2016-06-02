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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int take =0, notake =0;
        dfs(root, notake, take);
        return max(notake, take);
    }
    void dfs(TreeNode *root, int& notake, int& take)
    {
        if(root->left == NULL && root->right == NULL)
        {
            take= root->val;
            notake = 0;
            return ;
        }
        int ltake =0, lnotake=0, rtake=0, rnotake=0;
        if(root->left)
            dfs(root->left, lnotake, ltake);
        if(root->right)
            dfs(root->right, rnotake, rtake);
        
        notake = max(ltake, lnotake) +max(rtake, rnotake);
        take = root->val +lnotake+rnotake;
    }
};