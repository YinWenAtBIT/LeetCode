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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildT(nums, 0, nums.size());
    }
    TreeNode* buildT(vector<int>& nums, int start, int len)
    {
        if(!len)
            return NULL;
        TreeNode *new_one = new TreeNode(nums[start+len/2]);
        new_one->left = buildT(nums, start, len/2);
        new_one->right = buildT(nums, start+len/2+1, len -1-len/2);
        return new_one;
    }
};