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
    int sumNumbers(TreeNode* root) {
        int sum =0;
        int temp =0;
        dfs(root, temp, sum);
        return sum;
    }
    void dfs(TreeNode *root, int temp, int &sum)
    {
        if(!root)
        {
            sum+= temp;
            return;
        }
        temp = temp*10+root->val;
        if(root->left && root ->right)
        {
            dfs(root->left, temp, sum);
            dfs(root->right, temp, sum);
        }
        else if(root->left)
        {
            dfs(root->left, temp, sum);
        }
        else
        {
            dfs(root->right, temp, sum);
        }
    }
    
};