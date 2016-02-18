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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size();
        TreeNode * head = buildT(preorder, 0, len1, inorder, 0);
        return head;
    }
    TreeNode * buildT(vector<int>& preorder, int p_start, int p_len, vector<int>& inorder, int i_start)
    {
        if(!p_len)
            return NULL;
        TreeNode * new_one = new TreeNode(preorder[p_start]);
        int mid;
        for(mid=i_start; mid<i_start+p_len; mid++)
            if(preorder[p_start] == inorder[mid])
                break;
        int left_len = mid - i_start;
        new_one->left = buildT(preorder, p_start+1, left_len, inorder, i_start);
        new_one->right = buildT(preorder, p_start+left_len+1, p_len -left_len-1, inorder, mid+1);
        return new_one;
    }
    
};