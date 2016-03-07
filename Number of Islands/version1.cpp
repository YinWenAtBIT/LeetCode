class Solution {
public:
    int nx[4] = {1,0,0,-1};
    int ny[4] = {0,1,-1,0};
    int row, col;
    vector<vector<bool>> visited;
    
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if(!row)
            return 0;
        col = grid[0].size();
        if(!col)
            return 0;
        vector<bool> temp(col, false);
        visited.assign(row, temp);
        
        int count =0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == '0')
                    visited[i][j] = true;
                else if(visited[i][j] == false)
                {
                    visited[i][j] = true;
                    count++;
                    bfs(grid, i, j);
                }
            }
        return count;
    }
    bool judge(int x, int y)
    {
        if(x >=0 && x<row && y>=0 && y<col)
            return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        int tx, ty;
        queue<pair<int, int>> que;
        que.push(pair<int, int>(x,y));
        while(!que.empty())
        {
            x = que.front().first;
            y = que.front().second;
            que.pop();
            for(int i=0; i<4; i++)
            {
                tx = x+nx[i];
                ty = y+ny[i];
                if(judge(tx, ty) && grid[tx][ty] == '1' && visited[tx][ty] == false)
                {
                    visited[tx][ty] = true;
                    que.push(pair<int, int>(tx, ty));
                }
            }
        }
    }
};