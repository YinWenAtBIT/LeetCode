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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len1 = inorder.size();
        TreeNode * head = buildT(inorder, 0, len1, postorder, 0);
        return head;
    }
    TreeNode * buildT(vector<int>& inorder, int i_start, int i_len, vector<int>& postorder, int p_start)
    {
        if(!i_len)
            return NULL;
        TreeNode * new_one = new TreeNode(postorder[p_start+i_len-1]);
        int mid;
        for(mid=i_start; mid<i_start+i_len; mid++)
            if(postorder[p_start+i_len-1] == inorder[mid])
                break;
        int left_len = mid - i_start;
        new_one->left = buildT(inorder, i_start, left_len, postorder, p_start);
        new_one->right = buildT(inorder, mid+1, i_len -left_len-1, postorder, p_start+left_len);
        return new_one;
    }
    
};