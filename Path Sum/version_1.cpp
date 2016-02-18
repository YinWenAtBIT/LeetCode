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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(root->left && root->right)
        {
            if(hasPathSum(root->left, sum - root->val))
                return true;
            if(hasPathSum(root->right, sum - root->val))
                return true;
        }
        else
        {
            if(root->left)
            {
                if(hasPathSum(root->left, sum - root->val))
                    return true;
            }
            else if(root->right)
            {
                if(hasPathSum(root->right, sum - root->val))
                    return true;
            }
            else
            {
                if(root->val == sum)
                    return true;
            }
        }
        return false;
    }
};