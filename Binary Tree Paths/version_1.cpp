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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        string temp;
        dfs(root, res, temp);
        return res;
    }
    void dfs(TreeNode *root, vector<string> &res, string &temp)
    {
        string num = to_string(root->val);
        if(root->left || root->right)
        {
            
            temp+=num+"->";
            if(root->left)
                dfs(root->left, res, temp);
            if(root->right)
                dfs(root->right, res, temp);
            temp.resize(temp.size()-num.size()-2);
        }
        else
        {
            temp += num;
            res.push_back(temp);
            temp.resize(temp.size()-num.size());
        }
    }
};