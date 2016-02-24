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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
            
        stack<TreeNode *> st;
        TreeNode * now =root;
        while(!st.empty() || now)
        {
            while(now)
            {
                res.push_back(now->val);
                st.push(now);
                now = now->left;
            }
            if(!st.empty())
            {
                now = st.top();
                st.pop();
                now = now ->right;
            }
        }
        return res;
    }
};