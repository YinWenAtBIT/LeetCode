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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *now = head;
        head = NULL;
        ListNode *temp;
        while(now)
        {
            temp = now->next;
            now->next = head;
            head =now;
            now = temp;
        }
        return head;
    }
};