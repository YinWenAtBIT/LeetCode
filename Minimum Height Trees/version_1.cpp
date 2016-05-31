class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(!n)
            return res;
        vector<int> root_len;
        for(int i=0; i<n; i++)
        {
            visited.assign(n-1, false);
            int len =0;
            for(int j=0; j<n-1; j++)
            {
                if(edges[j].first == i)
                {
                    visited[j] = true;
                    dfs(edges, edges[j].second, 1, len);
                }
                if(edges[j].second == i)
                {
                    visited[j] = true;
                    dfs(edges, edges[j].first, 1, len);
                }
            }
            root_len.push_back(len);
        }
        int min_one = INT_MAX;
        for(int i=0; i<n; i++)
            if(min_one>root_len[i])
                min_one = root_len[i];
                
        for(int i=0; i<n; i++)
            if(root_len[i] == min_one)
                res.push_back(i);
        return res;
    }
    
    void dfs(vector<pair<int, int>>& edges, int start, int now, int &len)
    {
        for(int i=0; i<edges.size(); i++)
        {
            if(!visited[i])
            {
                if(edges[i].first == start)
                {
                    visited[i] = true;
                    dfs(edges, edges[i].second, now+1, len);
                }
                if(edges[i].second == start)
                {
                    visited[i] = true;
                    dfs(edges, edges[i].first, now+1, len);
                }                
            }
        }
        if(now>len)
            len  = now;
        
    }
    
private:
    vector<bool> visited;
};