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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * ret =head;
        if(!head || k<=0)
            return ret;
        ListNode **pCur = &ret;
        ListNode *next = NULL;
        
        vector<ListNode *> tmp(k);
        int i;
        bool flag = true;
        while(head)
        {
            for(i =0; i<k; i++)
            {
                if(head)
                {
                    tmp[i] = head;
                    head = head ->next;
                }
                else
                    break;
            }
            if(i != k)
                break;
            
            for(i = k-1;i>=0; i--)
            {
                *pCur = tmp[i];
                pCur = &(*pCur)->next;
            }
            
        }
        if(i>0)
            *pCur  = tmp[0];
        else
            *pCur = NULL;
        
        return ret;
    }
};