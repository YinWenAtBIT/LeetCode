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
        while(first)
        {
            TreeLinkNode * now =first;
            TreeLinkNode * pos1 =NULL;
            TreeLinkNode * pos2 =NULL;
            while(now)
            {
                if(now->left)
                {
                    pos1 = now->left;
                    break;
                }
                if(now->right)
                {
                    pos1 = now->right;
                    break;
                }
                now = now->next;
            }
            if(!pos1)
                break;
                
            first = pos1;
            bool flag = false;
            while(now)
            {
                
                if(now->left && now->right)
                {
                    if(!flag)
                    {
                        pos2 = now->right;
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                    }
                    
                }
                if(!pos2)
                {
                    now = now->next;
                    while(now)
                    {
                        if(now->left)
                        {
                            pos2 = now->left;
                            break;
                        }
                        if(now->right)
                        {
                            pos2 = now->right;
                            break;
                        }
                        now = now->next;
                    }
                }
                pos1 ->next = pos2;
                pos1 =pos2;
                pos2 = NULL;
            }

        }
    }
};