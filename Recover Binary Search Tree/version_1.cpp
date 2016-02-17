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
        vector<int> save = inorderTraversal(root);
        sort(save.begin(), save.end());
        inorderAssign(root, save);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        stack<TreeNode *> st;
        TreeNode * now = root;
        
        while(!st.empty() || now)
        {
            while(now)
            {
                st.push(now);
                now = now->left;
            }
            TreeNode * read = st.top();
            st.pop();
            res.push_back(read->val);
            now = read ->right;
        }
        
        return res;
    }
    void inorderAssign(TreeNode* root, vector<int> & nums)
    {
        int len = nums.size();
        int i=0;
        stack<TreeNode *> st;
        TreeNode * now = root;

        
        while(!st.empty() || now)
        {
            while(now)
            {
                st.push(now);
                now = now->left;
            }
            TreeNode * read = st.top();
            st.pop();
            read->val = nums[i];
            i++;
            now = read ->right;
        }        
    }
};