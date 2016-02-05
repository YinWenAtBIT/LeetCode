class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        vector<bool> check_row(false,10);
        vector<bool> check_line(false,10);
        for(int i=0; i<9; i++)
        {
            for(int k=0; k<10; k++)
            {
                check_row[k] = false;
                check_line[k] = false;
            }
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num_i_j = board[i][j]-'0';
                    if(!check_row[num_i_j])
                        check_row[num_i_j] = true;
                    else
                    {
                        valid = false;
                        break;
                    }
                } 
                if(board[j][i] != '.')
                {
                    int num_j_i = board[j][i]-'0';
                    if(!check_line[num_j_i])
                        check_line[num_j_i] = true;
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid)
                break;
        }
        
        for(int i=0; i<=6; i+=3)
        {
            for(int j=0; j<=6; j+=3)
            {
                for(int k=0; k<10; k++)
                    check_row[k] = false;
                    
                for(int k=0; k<9; k++)
                {
                    if(board[i+k/3][j+k%3] != '.')
                    {
                        int num_k = board[i+k/3][j+k%3] -'0';
                        if(!check_row[num_k])
                            check_row[num_k] = true;
                        else
                        {
                            valid = false;
                            break; 
                        }
                    }

                }
                
                if(!valid)
                    break;
            }
            if(!valid)
                break;
        }
        return valid;
        
    }
};