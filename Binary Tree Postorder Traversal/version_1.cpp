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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        stack<pair<TreeNode *, bool>> st;
        TreeNode * now = root;
        while(!st.empty() || now)
        {
            while(now)
            {
                st.push(pair<TreeNode*, bool>(now, false));
                now = now ->left;
            }

            pair<TreeNode *, bool> &read = st.top();
            
            if(read.second)
            {
                res.push_back(read.first->val);
                st.pop();
            }
            else
            {
                now = read.first->right;
                read.second = true;
                
            }
        }
        return res;
    }
};