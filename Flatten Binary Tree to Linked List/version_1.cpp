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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode * now = root;
        while(!st.empty() || now)
        {
            while(now)
            {
                if(now->right)
                    st.push(now->right);
                if(now->left)
                {
                    now->right = now->left;
                    now->left = NULL;
                    now = now->right;
                }
                else
                    break;
            }
            if(!st.empty())
            {
                now->right = st.top();
                now = now->right;
                st.pop();
            }
            else
                now = NULL;
        }
    }
};