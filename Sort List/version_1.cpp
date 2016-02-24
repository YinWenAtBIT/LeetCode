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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * temp = NULL;
        while(fast && fast->next)
        {
            fast = fast ->next->next;
            temp = slow;
            slow = slow->next;
        }
        temp ->next = NULL;
        
        ListNode * head1 = sortList(head);
        ListNode * head2 = sortList(slow);
        
        ListNode *new_head;
        if(head1->val < head2->val)
        {
            new_head = head1;
            head1 = head1->next;
        }
        else
        {
            new_head = head2;
            head2 = head2->next;
        }
        ListNode * now = new_head;
        while(head1 && head2)
        {
            if(head1 ->val <head2->val)
            {
                now ->next = head1;
                now = now->next;
                head1 = head1->next;
            }
            else
            {
                now->next = head2;
                now = now->next;
                head2 = head2->next;
            }
        }
        if(head1)
            now->next = head1;
        if(head2)
            now->next = head2;
        
        return new_head;
    }
};