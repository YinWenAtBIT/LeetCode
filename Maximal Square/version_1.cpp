class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len_row = matrix.size();
        if(!len_row)
            return 0;
        int len_col = matrix[0].size();
        if(!len_col)
            return 0;
            
        int size = 0;
        for(int i=0; i<len_row; i++)
        {
            if(size+i>len_row)
                break;
            for(int j=0; j<len_col; j++)
            {
                if(size+j>len_col)
                    break;
                int temp = max_len(matrix, i, j);
                if(size<temp)
                    size = temp;
            }
        }
        return size*size;
    }
    
    int max_len(vector<vector<char>>& matrix, int row, int col)
    {
        int len_row = matrix.size();
        int len_col = matrix[0].size();
        
        int cycle = min(len_row-row, len_col -col);
        int count =0;
        for(int i=0; i<cycle; i++)
        {
            bool flag = true;
            for(int j=0; j<=i; j++)
            {
                if(!flag)
                    break;
                for(int k=0; k<=i; k++)
                {
                    if(matrix[row+j][col+k] == '0')
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                count++;
            else
                break;
        }
        return count;
    }
};