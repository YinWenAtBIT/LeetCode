/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        queue<UndirectedGraphNode *> que;
        unordered_map<int, UndirectedGraphNode*> dic;
        unordered_set<int> used;
        used.insert(node->label);
        que.push(node);
        UndirectedGraphNode * now;
        while(!que.empty())
        {
            now = que.front();
            que.pop();
            UndirectedGraphNode * new_one = new UndirectedGraphNode(now->label);
            dic[new_one->label] = new_one;
            
            for(int i=0; i<now->neighbors.size(); i++)
            {
                UndirectedGraphNode * temp = now->neighbors[i];
                if(!used.count(temp->label))
                {
                    used.insert(temp->label);
                    que.push(temp);
                }
            }
        }
        
        used.clear();
        que.push(node);
        used.insert(node->label);
        while(!que.empty())
        {
            now = que.front();
            que.pop();     
            
            UndirectedGraphNode *new_one = dic[now->label];
            for(int i=0; i<now->neighbors.size(); i++)
            {
                UndirectedGraphNode * temp = now->neighbors[i];
                if(!used.count(temp->label))
                {
                    used.insert(temp->label);
                    que.push(temp);
                }
                    
                new_one->neighbors.push_back(dic[temp->label]);
            }            
        }
        return dic[node->label];
    }
};