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
    bool isPalindrome(ListNode* head) {
        ListNode * fast = head;
        ListNode *slow = head;
        while(fast &&fast ->next)
        {
            slow = slow ->next;
            fast = fast->next->next;
        }
        if(fast)
        {
            slow->next = reverseList(slow->next);
            slow = slow->next;
        }
        else
            slow= reverseList(slow);
        
        while(slow)
        {
            if(slow->val == head->val)
            {
                slow = slow->next;
                head = head->next;
            }
            else
                return false;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        else if(head->next->next == NULL)
        {
            ListNode* newhead = head->next;
            newhead->next = head;
            head->next = NULL;
            return newhead;
        }
        else
        {
            ListNode* pre = head;
            ListNode* cur = pre->next;
            pre->next = NULL;
            ListNode* post = cur->next;
            
            while(post != NULL)
            {
                cur->next = pre;
                pre = cur;
                cur = post;
                post = post->next;
            }
            cur->next = pre;
            return cur;
        }
    }
};