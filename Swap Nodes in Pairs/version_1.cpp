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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ret = head;
        if(!ret || ret->next == NULL)
            return ret;
            
        ListNode **pCur = &ret;
        ListNode *next = NULL;
        while(head && head->next)
        {
            next = head->next->next;
            *pCur = head->next;
            pCur = &(*pCur)->next;
            *pCur = head;
            pCur = &(*pCur)->next;
            head = next;
        }
        *pCur = head;
        return ret;
    }
};