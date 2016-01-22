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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;

        int carry =0;
        int temp;
        ListNode* next1 = l1;
        ListNode* next2 = l2;
        ListNode* last;
        ListNode* head;
        
        while(next1 !=NULL && next2 != NULL)
        {
            next1 = next1->next;
            next2 = next2->next;
        }
        if(next1 == NULL)
        {
            head = l2;
            next1 = l2;
            next2 = l1;
        }
        else
        {
            head = l1;
            next1 = l1;
            next2 = l2;
        }
        
        while(next1 != NULL)
        {
            if(next2 != NULL)
            {
                temp = next1->val + next2->val+carry;
                next2 = next2->next;
            }
            else
                temp = next1->val + carry;
            carry = 0;
            if(temp >9)
            {
                temp = temp -10;
                carry = 1;
            }
            
            next1->val = temp;
            
            last = next1;
            next1 = next1->next;
            
        }
        
        if(carry ==1)
        {
            last->next = new struct ListNode(carry);
        }
        return head;
    }
};