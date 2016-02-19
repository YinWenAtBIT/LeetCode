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
        queue<TreeLinkNode *> que;
        que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            vector<int> temp;
            TreeLinkNode *now = NULL;
            while(len)
            {
                now = que.front();
                que.pop();
                len--;
                if(now->left)
                    que.push(now->left);
                if(now->right)
                    que.push(now->right);
                if(len)
                    now->next = que.front();
            }

        }
    }
};