class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int word_len = word.size();
        if(!m || !word_len)
            return false;
        int n = board[0].size();
        
        vector<vector<bool>> flag(m);
        for(int i=0; i<m; i++)
            flag[i].assign(n, false);
        
        list<char> temp(word.begin(), word.end());
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(flag[i][j])
                    continue;
                if(dfs(board, flag, temp, i, j))
                    return true;
            }
        
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>> &flag, list<char> &temp, int row, int col)
    {
        
        if(flag[row][col])
            return false;
        
        flag[row][col] = true;

        if(board[row][col] == temp.front())
        {
            temp.pop_front();
            if(temp.empty())
                return true;
            if(row -1 >=0)
            {
                if(dfs(board, flag, temp, row-1, col))
                    return true;
            }
            if(col-1>=0)
            {
                if(dfs(board, flag, temp, row, col-1))
                    return true;                    
            }                
            if(row +1 <board.size())
            {
                if(dfs(board, flag, temp, row+1, col))
                    return true;
            }
            if(col+1<board[0].size())
            {
                if(dfs(board, flag, temp, row, col+1))
                    return true;                    
            }
            temp.push_front(board[row][col]);

        }
        
        flag[row][col] = false;
        return false;
    }
    
    
};