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
    bool isBalanced(TreeNode* root) {
        int temp;
        return is_B(root, temp);
    }
    bool is_B(TreeNode * root, int &depth)
    {
        if(!root)
        {
            depth = 0;
            return true;
        }
        int left, right;
        if(!is_B(root->left, left))
            return false;
        if(!is_B(root->right, right))
            return false;
        if(abs(left-right)>1)
            return false;
        depth = max(left, right)+1;
        return true;
    }
};