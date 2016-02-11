class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if(len<2)
            return;
        int new_i, new_j, old_i, old_j;
        int temp_old =0;
        int temp_new =0;
        for(int i=0; i<len/2;i++)
        {
            for(int j=i; j<len-1-i; j++)
            {
                old_i = i;
                old_j = j;
                temp_old = matrix[i][j];
                for(int k=0; k<4;k++)
                {
                    new_i = old_j;
                    new_j = len-1-old_i;
                    temp_new = matrix[new_i][new_j];
                    matrix[new_i][new_j] = temp_old;
                    
                    old_i = new_i;
                    old_j = new_j;
                    temp_old = temp_new;
                }
            }
        }
    }
};