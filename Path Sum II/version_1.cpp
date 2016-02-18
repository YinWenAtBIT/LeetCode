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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        PathSum(res, temp, root, sum);
        return res;
    }
    void PathSum(vector<vector<int>> &res, vector<int> &temp, TreeNode* root, int sum) {
        if(!root)
            return;
        temp.push_back(root->val);
        if(root->left && root->right)
        {
            PathSum(res, temp, root->left, sum - root->val);
            PathSum(res, temp, root->right, sum - root->val);
        }
        else
        {
            if(root->left)
                PathSum(res, temp, root->left, sum - root->val);
            else if(root->right)
                PathSum(res, temp, root->right, sum - root->val);
            else if(root->val == sum)
                res.push_back(temp);
        }
        temp.pop_back();
    }
};