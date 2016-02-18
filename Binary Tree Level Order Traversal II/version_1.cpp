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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> que;
        deque<vector<int>> ret;
        que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            vector<int> temp;
            TreeNode *now = NULL;
            while(len)
            {
                now = que.front();
                que.pop();
                temp.push_back(now->val);
                len--;
                if(now->left)
                    que.push(now->left);
                if(now->right)
                    que.push(now->right);
                
            }
            ret.push_front(temp);

        }
        res.assign(ret.begin(), ret.end());
        return res;
    }
};