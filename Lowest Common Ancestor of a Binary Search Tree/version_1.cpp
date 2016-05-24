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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        TreeNode * now = root;
        while(now)
        {
            if(p->val <now->val && q->val<now->val)
                now = now->left;
            else if(p->val >now->val && q->val>now->val)
                now = now->right;
            else
                return now;
        }
        return now;
    }
};