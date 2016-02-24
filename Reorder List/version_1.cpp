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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        
        deque<ListNode *> que;
        ListNode * now = head;
        while(now)
        {
            que.push_back(now);
            now = now->next;
        }
        while(!que.empty())
        {
            ListNode *front = que.front();
            que.pop_front();
            if(que.empty())
            {
                front->next = NULL;
                break;
            }
                
            ListNode *back = que.back();
            que.pop_back();
            front ->next = back;
            if(!que.empty())
                back->next = que.front();
            else
                back->next = NULL;
        }
    }
};