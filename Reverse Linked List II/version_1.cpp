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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        
        ListNode *before=NULL, *end = NULL;
        ListNode* start = head;
        n = n-m;
        while(m>1)
        {
            m--;
            before = start;
            start = start->next;
        }
        end = start->next;
        ListNode *pos = start;
        ListNode *temp;
        while(n>0)
        {
            temp = end->next;
            end->next = pos;
            pos = end;
            end = temp;
            n--;
        }
        if(before != NULL)
            before->next = pos;
        
        else
            head = pos;
        
        start->next = end;
        return head;
    }
};