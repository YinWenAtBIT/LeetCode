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
        if(!head)
            return head;
        ListNode *before = head;
        ListNode *nxt = head->next;
        while(nxt)
        {
            if(before->val == nxt->val)
            {
                ListNode *temp = nxt;
                before->next = nxt->next;
                nxt = nxt->next;
                free(temp);
            }
            else
            {
                before = nxt;
                nxt = nxt->next;
            }
        }
        return head;
    }
};