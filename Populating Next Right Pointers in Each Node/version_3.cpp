/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode * first = root;
        while(first->left)
        {
            TreeLinkNode * now =first;
            while(now)
            {
                now->left->next = now->right;
                if(now->next)
                    now->right->next = now->next->left;
                now = now->next;
            }
            first = first->left;
        }
    }
};