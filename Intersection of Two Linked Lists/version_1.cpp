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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA | !headB)
            return NULL;
        ListNode * nowA = headA;
        ListNode * nowB = headB;
        
        int countA =0, countB=0;
        while(nowA)
        {
            nowA= nowA->next;
            countA++;
        }
        while(nowB)
        {
            nowB= nowB->next;
            countB++;
        }
        
        nowA= headA;
        nowB= headB;
        if(countB>countA)
        {
            int diff = countB-countA;
            while(diff)
            {
                nowB = nowB->next;
                diff--;
            }
        }
        else
        {
            int diff = countA-countB;
            while(diff)
            {
                nowA= nowA->next;
                diff--;
            }
        }
        while(nowA)
        {
            if(nowA == nowB)
                return nowA;
            nowA = nowA->next;
            nowB = nowB->next;
        }
        return NULL;
    }
};