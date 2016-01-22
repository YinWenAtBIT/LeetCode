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
        ListNode* next1 = l1;
        ListNode* next2 = l2;
        ListNode* last;
        ListNode* head = l1;
        

        while(next1 != NULL | next2 != NULL)
        {
            if(next1 && next2 )
            {
                temp = next1->val + next2->val+carry;
                
                carry = 0;
                if(temp >9)
                {
                    temp -= 10;
                    carry = 1;
                }
                next1 -> val = temp;
                next2 -> val = temp;
                
                
                last = next1;
                next2 = next2->next;
                next1 = next1->next;
            }
            else
            {
                if(next1)
                {
                    temp = next1->val + carry;
                    carry = 0;
                    if(temp >9)
                    {
                        temp -= 10;
                        carry = 1;
                    }
                    next1 ->val = temp;
                    last = next1;
                    next1 = next1->next;
                    
                }
                else
                {
                    temp = next2->val + carry;
                    carry = 0;
                    if(temp >9)
                    {
                        temp -= 10;
                        carry = 1;
                    }
                    next2 ->val = temp;
                    last = next2;
                    next2 = next2->next; 
                    head = l2;
                }
                
            }
            
        }
        
        if(carry ==1)
        {
            last->next = new struct ListNode(carry);
        }
        return head;
    }
};