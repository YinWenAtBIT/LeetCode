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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        int max_depth =0;
        dfs(res, root, 0, max_depth);
        return res;
        
    }
    void dfs(vector<int> &res, TreeNode *root, int depth_before, int &depth_reached)
    {
        int now = depth_before+1;
        if(now>depth_reached)
        {
            res.push_back(root->val);
            depth_reached = now;
        }
        if(root->right)
            dfs(res, root->right, now, depth_reached);
        if(root->left)
            dfs(res, root->left, now, depth_reached);
    }
};