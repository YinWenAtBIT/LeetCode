class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve_shudo(board);
    }
    bool solve_shudo(vector<vector<char>>& board)
    {

            
        int i, j;
        bool flag =false;
        for(i=0; i<9; i++)
        {
            for(j =0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    flag = true;
                    break;
                }

            }
            if(flag)
                break;
        }
                    
        if(i==9 && j==9)
            return true;
 
        set<int> all_number;
        for(int k=1; k<10; k++)
            all_number.insert(k);
            
        for(int k =0; k<9; k++)
        {
            if(board[i][k] !='.')
            {
                int number = board[i][k] -'0';
                if(all_number.find(number) != all_number.end())
                    all_number.erase(number);
            }
            if(board[k][j] != '.')
            {
                int number = board[k][j] -'0';
                if(all_number.find(number) != all_number.end())
                    all_number.erase(number);
            }
                
            if(board[i/3*3+k/3][j/3*3 +k%3] != '0')
            {
                int number = board[i/3*3+k/3][j/3*3 +k%3] -'0';
                if(all_number.find(number) != all_number.end())
                    all_number.erase(number);
            }
        }
        
        if(all_number.empty())
            return false;
        set<int>::iterator it;
        for(it = all_number.begin(); it != all_number.end(); it++)
        {
            board[i][j] = *it +'0';
            if(solve_shudo(board))
                return true;
        }
        board[i][j] ='.';
        return false;
    }
    
};