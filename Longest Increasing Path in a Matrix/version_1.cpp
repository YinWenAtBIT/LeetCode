class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if(!row)
            return 0;
        col = matrix[0].size();
        
        int vertex = row*col;
        indegree.assign(vertex, 0);
        int diff_x [] = {-1,0,0,1};
        int diff_y [] = {0,1,-1,0};
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<4; k++)
                {
                    int next_x = i+diff_x[k];
                    int next_y = j+diff_y[k];
                    if(is_valid(next_x, next_y) && matrix[i][j] < matrix[next_x][next_y])
                    {
                        graph[i*col+j].push_back(next_x*col+next_y);
                        indegree[next_x *col +next_y]++;
                    }
                }
        
        int max_len = 0;
        for(int i=0; i<vertex; i++)
            if(indegree[i] ==0)
                dfs(i, 1, max_len);
        
        return max_len;
    }
    
    void dfs(int now_index, int count, int &max_len)
    {
        vector<int> & next_vertex = graph[now_index];
        int len = next_vertex.size();
        if(!len && count >max_len)
            max_len =count;
        
        for(int i=0; i<len; i++)
            dfs(next_vertex[i], count+1, max_len);
            
    }
    
    bool is_valid(int x, int y)
    {
        return x>=0 &&x <row && y>=0 && y<col;
    }
private:
    int row, col;
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;
};