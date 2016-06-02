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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode * l=NULL, *r = NULL;
        bool odd_flag = true;
        seprate(head, l, r, odd_flag, l, r);
        return l;
    }
    void seprate(ListNode* head, ListNode *&lnext, ListNode* &rnext, bool odd_flag, ListNode* &lhead, ListNode *&rhead)
    {
        if(odd_flag)
        {
            ListNode* temp = head->next;
            head->next = NULL;
            lnext = head;
            if(temp)
                seprate(temp, lnext->next, rnext, !odd_flag, lhead, rhead);
            else
                lnext->next = rhead;
        }
        else
        {
            ListNode* temp = head->next;
            head->next = NULL;
            rnext = head;
            if(temp)
                seprate(temp, lnext, rnext->next, !odd_flag, lhead, rhead);
            else
                lnext = rhead;            
        }
    }
};