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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        stack<TreeNode *> st_l;
        stack<TreeNode *> st_r;
        TreeNode * now_right = root;
        TreeNode * now_left =  root;
        
        while(!st_l.empty() || now_left)
        {
            while(now_left)
            {
                st_l.push(now_left);
                now_left = now_left->left;
            }
            while(now_right)
            {
                st_r.push(now_right);
                now_right = now_right->right;
            }
            
            TreeNode * read_left = st_l.top();
            st_l.pop();
            TreeNode * read_right = st_r.top();
            st_r.pop(); 
            if(read_left->val != read_right->val)
                return false;
            now_left = read_left->right;
            now_right = read_right->left;
        }
        now_right = root;
        now_left =  root;
        
        while(!st_l.empty() || now_left)
        {
            while(now_left)
            {
                if(now_left->val != now_right->val)
                    return false;
                st_l.push(now_left);
                st_r.push(now_right);
                now_left = now_left->left;
                now_right = now_right->right;
            }
            TreeNode * read_left = st_l.top();
            TreeNode * read_right = st_r.top();
            st_l.pop();
            st_r.pop();
            now_left = read_left ->right;
            now_right = read_right ->left;
        }
        
        return true;
    }
};