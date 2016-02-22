class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(!row)
            return;
        int col = board[0].size();
        
        vector<vector<bool>> visited(row);
        for(int i=0; i<row; i++)
            visited[i].assign(col, false);
        
        queue<pair<int, int>> que;
        vector<pair<int, int>> loc_save;
        bool escape = false;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                {
                    escape = false;
                    visited[i][j] = true;
                    loc_save.clear();
                    loc_save.push_back(pair<int, int>(i,j));
                    que.push(pair<int, int>(i,j));
                    while(!que.empty())
                    {
                        pair<int, int> loc = que.front();
                        que.pop();
                        int ind_r = loc.first;
                        int ind_c = loc.second;
                        if(ind_r+1<row)
                        {
                            if(board[ind_r+1][ind_c] == 'O' && !visited[ind_r+1][ind_c])
                            {
                                visited[ind_r+1][ind_c] = true;
                                que.push(pair<int, int>(ind_r+1, ind_c));
                                loc_save.push_back(pair<int, int>(ind_r+1, ind_c));
                            }
                        }
                        else
                            escape = true;
                        
                        if(ind_r-1>=0)
                        {
                            if(board[ind_r-1][ind_c] == 'O' && !visited[ind_r-1][ind_c])
                            {
                                visited[ind_r-1][ind_c] = true;
                                que.push(pair<int, int>(ind_r-1, ind_c));
                                loc_save.push_back(pair<int, int>(ind_r-1, ind_c));
                            }
                        }
                        else
                            escape = true;   
        
                        if(ind_c+1<col)
                        {
                            if(board[ind_r][ind_c+1] == 'O' && !visited[ind_r][ind_c+1])
                            {
                                visited[ind_r][ind_c+1] = true;
                                que.push(pair<int, int>(ind_r, ind_c+1));
                                loc_save.push_back(pair<int, int>(ind_r, ind_c+1));
                            }
                        }
                        else
                            escape = true;
        
                        if(ind_c-1>=0)
                        {
                            if(board[ind_r][ind_c-1] == 'O' && !visited[ind_r][ind_c-1])
                            {
                                visited[ind_r][ind_c-1] = true;
                                que.push(pair<int, int>(ind_r, ind_c-1));
                                loc_save.push_back(pair<int, int>(ind_r, ind_c-1));
                            }
                        }
                        else
                            escape = true;
                    }
                    
                    if(!escape)
                    {
                        int len = loc_save.size();
                        int first;
                        int second;
                        for(int k=0; k<len; k++)
                        {
                            first = loc_save[k].first;
                            second = loc_save[k].second;
                            board[first][second] = 'X';
                        }
                    }
                }
            }
    }
};