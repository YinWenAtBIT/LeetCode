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
    ListNode* partition(ListNode* head, int x) {

        return new_head(head, x);
    }
    ListNode* new_head(ListNode* head, int x)
    {
        if(!head)
            return head;
        ListNode * insert_pos = head->val <x?head:NULL;
        if(head->val >=x)
        {
            ListNode * temp = head;
            while(temp->next && temp ->next->val>=x)
                temp = temp->next;
            if(!temp->next)
                return head;
            else
            {
                ListNode *T = temp->next->next;
                temp->next->next = head;
                head = temp->next;
                temp->next = T;
                head->next = new_head(head->next, x);
                return head;
            }
        }
        else
        {
            head->next = new_head(head->next, x);
            return head;
        }        
    }
    
};