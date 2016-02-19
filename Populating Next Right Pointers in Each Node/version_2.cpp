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
        next_to_right(root->left, root->right);

    }
    void next_to_right(TreeLinkNode *lchild, TreeLinkNode* rchild)
    {
        if(!lchild)
            return;
        lchild->next = rchild;
        next_to_right(lchild->left, lchild->right);
        next_to_right(lchild->right, rchild->left);
        next_to_right(rchild->left, rchild->right);
    }
};