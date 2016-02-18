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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        deque<TreeNode *> que;
        deque<TreeNode *> save;
        int depth =0;
        que.push_back(root);
        while(!que.empty())
        {
            int len = que.size();
            vector<int> temp;
            TreeNode *now = NULL;
            while(len)
            {
                if(depth%2)
                {
                    now = que.back();
                    que.pop_back();
                    if(now->right)
                        save.push_front(now->right);
                    if(now->left)
                        save.push_front(now->left);
                }
                else
                {
                    now = que.front();
                    que.pop_front();
                    if(now->left)
                        save.push_back(now->left);
                    if(now->right)
                        save.push_back(now->right);
                }
                
                len--;
                temp.push_back(now->val);
                

            }
            res.push_back(temp);
            que = save;
            save.clear();
            depth++;

        }
        return res;
    }
};