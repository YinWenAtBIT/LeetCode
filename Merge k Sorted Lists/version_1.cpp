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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ret = NULL;
        ListNode ** pCur = &ret;
        int len = lists.size();
        if(!len)
            return ret;
        bool flag = true;
        ListNode** temp =NULL;
        while(flag)
        {
            int min = 0x7fffffff;
            flag = false;
            for(int i=0; i<len; i++)
            {
                if(lists[i] && lists[i]->val <min)
                {
                    temp = &lists[i];
                    min = lists[i]->val;
                    flag = true;
                }
            }
			if(!flag)
				break;
            *pCur = *temp;
            pCur = &((*pCur)->next);
            *temp = (*temp)->next;
        }
        return ret;
    }
};