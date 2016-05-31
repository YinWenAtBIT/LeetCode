class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(!n)
            return res;
        vector<int> indegree(n, 0);
        remain.assign(n, true);
        for(int i=0; i<n-1; i++)
        {
            indegree[edges[i].first] ++;
            indegree[edges[i].second] ++;
        }
        int count =0;
        while(count< n -2)
        {
            vector<int> leaves;
            for(int i=0; i<n; i++)
                if(indegree[i] ==1)
                {
                    indegree[i] --;
                    remain[i] = false;
                    leaves.push_back(i);
                }
            count+= leaves.size();
            for(int i=0; i<leaves.size(); i++)
            {
                int leaf = leaves[i];
                for(int j=0; j<n-1; j++)
                {
                    if(edges[j].first == leaf)
                        indegree[edges[j].second]--;
                        
                    if(edges[j].second == leaf)
                        indegree[edges[j].first]--;
                }
            }
        }
        
        for(int i=0; i<n; i++)
            if(remain[i])
                res.push_back(i);
        
        return res;
    }
private:
    vector<bool> remain;
};