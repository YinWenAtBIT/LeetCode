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
    int kthSmallest(TreeNode* root, int k) {
        int res =0;
        find_k(root, k, res);
        return res;
    }
    
    bool find_k(TreeNode* root, int & now, int &res)
    {
        if(!root)
            return false;
            
        if(find_k(root->left, now, res))
            return true;
            
        now --;
        if(now == 0)
        {
            res = root->val;
            return true;
        }
        
        if(find_k(root->right, now, res))
            return true;
        
        return false;
    }
};