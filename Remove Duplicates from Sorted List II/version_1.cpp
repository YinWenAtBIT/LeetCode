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
    ListNode* deleteDuplicates(ListNode* head) {
        return find_first_unique(head);
    }
    ListNode* find_first_unique(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode * new_head = NULL;
        ListNode * before = head;
        ListNode * nxt = head->next;
        while(nxt && before->val == nxt->val)
        {
            while(nxt && before->val == nxt->val)
            {
                before = nxt;
                nxt= nxt->next;
            }
            if(!nxt)
                return new_head;
            else
            {
                before = nxt;
                nxt = nxt->next;
            }
        }
        
        new_head = before;
        new_head->next = find_first_unique(nxt);
        return new_head;
    }
};