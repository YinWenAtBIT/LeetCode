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
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        

        
        stack<TreeNode *> st;
        TreeNode * now = root;
        TreeNode * cur_b= NULL;
        TreeNode * cur_l = NULL;
        while(!st.empty() || now)
        {
            while(now)
            {
                st.push(now);
                now = now->left;
            }
            TreeNode * read = st.top();
            cur_b = cur_l;
            cur_l = read;
            if(cur_b)
            {
                if(cur_l->val <= cur_b->val)
                {
                    if(left)
                    {
                        right = cur_l;
                    }
                    else
                    {
                        left = cur_b;
                        right = cur_l;
                    }
                }
            }
            st.pop();
            now = read ->right;
        }
        
        swap(left->val, right->val);
        
    }
};