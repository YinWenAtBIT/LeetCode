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
        if(!l1 & !l2)
            return NULL;

        int carry =0;
        int temp;
        int temp_res;
        ListNode* next1 = l1;
        ListNode* next2 = l2;
        ListNode* last;
        ListNode* head = l1;
        

        while(next1 && next2)
        {
            temp = next1->val + next2->val+carry;
            temp_res = temp%10;
            carry = temp/10;

            next1 -> val = temp_res;
            next2 -> val = temp_res;
    
            last = next1;
            next2 = next2->next;
            next1 = next1->next;
        }
        
        if(next1)
        {
            while(next1)
            {
                temp = next1->val + carry;
                carry = temp/10;
                next1 ->val = temp%10;
                last = next1;
                next1 = next1->next;
            }
            
        }
        if(next2)
        {
            head = l2;
            while(next2)
            {
                temp = next2->val + carry;
                carry = temp/10;
    
                next2 ->val = temp%10;
                last = next2;
                next2 = next2->next; 
            }
        }
        
        if(carry)
        {
            last->next = new struct ListNode(carry);
        }
        return head;
    }
};