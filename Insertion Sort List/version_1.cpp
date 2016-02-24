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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
        ListNode * now;
        ListNode * pos = head->next;
        ListNode * end = head;
        while(pos)
        {
            end->next = NULL;
            now = pos;
            pos = pos->next;
            ListNode * start = head;
            ListNode * before = NULL;
            while(start)
            {
                if(now->val> start->val)
                {  
                    before = start;
                    start = start->next;
                }
                else
                    break;
            }
            if(before == NULL)
            {
                now->next = head;
                head = now;
            }
            else
            {
                before->next = now;
                if(start == NULL)
                    end = now;
                else
                    now->next = start;
            }
            
        }
        return head;
    }
};