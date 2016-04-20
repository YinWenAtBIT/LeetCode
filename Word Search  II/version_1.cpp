class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int num = words.size();
        vector<string> res;
            
        row = board.size();
        if(!num || !row)
            return res;
            
        col = board[0].size();
        for(int i=0; i<num; i++)
        {
            string now = words[i];
            for(int j=0; j<row; j++)
                for(int k=0; k<col; k++)
                {
                    if(board[j][k] == now[0])
                    {
                        board[j][k] = '#';
                        if(dfs(board, now, 1, j, k))
                            res.push_back(now);
                        board[j][k] = now[0];
                    }
                }
        }
    }
    
    bool dfs(vector<vector<char> > &board, string &word, int cnt, int x, int y) {
        if (cnt == word.length()) {
            return true;
        }
        int tx, ty;
        for (int i = 0; i < 4; i++) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (judge(tx, ty) && board[tx][ty] == word[cnt]) {
                board[tx][ty] = '#';
                if (dfs(board, word, cnt + 1, tx, ty)) {
                    board[tx][ty] = word[cnt];
                    return true;
                }
                board[tx][ty] = word[cnt];
            }
        }
        return false;
    }
    
    bool judge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    
private:
    int row, col;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
};