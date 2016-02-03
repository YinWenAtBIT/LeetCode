/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
            
        ListNode *head = NULL;
        ListNode * right, * left;
        if(l1->val <l2->val)
        {
            head = l1;
            left = l1->next;
            right = l2;
        }
        else
        {
            head = l2;
            left = l1;
            right = l2->next;
        }
        ListNode * before = head;
        while(left && right)
        {
            if(left->val < right ->val)
            {
                before ->next = left;
                left = left ->next;
                before = before ->next;
            }
            else
            {
                before ->next = right;
                right = right ->next;
                before = before ->next;                
            }
        }
        if(left)
            before->next = left;
        else
            before->next = right;
            
        return head;
    }
};