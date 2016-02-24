/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        RandomListNode *now = head;
        unordered_map<RandomListNode *, RandomListNode*> dic;
        RandomListNode *new_head = new RandomListNode(now->label);
        RandomListNode * new_one = new_head;
        dic[head] = new_head;
        while(now->next)
        {
            now = now->next;
            new_one ->next = new RandomListNode(now->label);
            new_one = new_one ->next;
            dic[now] = new_one;
        }
        
        now = head;
        new_one = new_head;
        while(now)
        {
            int count =0;
            RandomListNode * temp = now->random;
            if(temp == NULL)
                new_one->random = NULL;
            else
                new_one ->random = dic[temp];
            
            now = now->next;
            new_one = new_one->next;
        }
        
        return new_head;
    }
};