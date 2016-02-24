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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode *first = head->next;
        ListNode *second  = head->next->next;
        while(second)
        {
            if(second == first)
                return true;
            first= first->next;
            second =second ->next;
            if(!second)
                return false;
            second = second ->next;
        }
        return false;
    }
};