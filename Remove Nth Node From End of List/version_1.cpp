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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head ||head->next == NULL)
            return NULL;
            
        ListNode *before = head;
        ListNode *current = head;
        ListNode *last = head;
        while(last && n)
        {
            last = last->next;
            n--;
        }
        if(!last)
            return head->next;
            
        while(last)
        {
            last = last ->next;
            before = current;
            current = current->next;
        }
        before ->next = current ->next;
        return head;
    }
};