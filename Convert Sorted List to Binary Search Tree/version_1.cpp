/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int count =0;
        ListNode *now = head;
        while(now)
        {
            count++;
            now = now->next;
        }
        return buildT(head, count);
    }
    TreeNode* buildT(ListNode* head, int len)
    {
        if(!len)
            return NULL;
        ListNode *now = head;
        int mid = len/2;
        while(mid)
        {
            mid--;
            now = now->next;
        }
        
        TreeNode *new_one = new TreeNode(now->val);
        new_one->left = buildT(head, len/2);
        new_one->right = buildT(now->next, len -1-len/2);
        return new_one;
    }
};