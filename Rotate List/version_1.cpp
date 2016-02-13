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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        int len=0;
        ListNode *before = head, *last=head;
        while(before)
        {
            before = before->next;
            len++;
        }
        k = k%len;
        if(!k)
            return head;
            
        before = head;
        while(k && before->next)
        {
            before = before->next;
            k--;
        }
        if(k)
            return head;
        while(before->next)
        {
            before = before->next;
            last = last->next;
        }
        ListNode *temp =head;
        head= last->next;
        last->next = before->next;
        before->next = temp;
        return head;
        
    }
};