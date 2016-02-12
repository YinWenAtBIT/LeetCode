class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        vector<int> res;
        if(!row)
            return res;
        int col = matrix[0].size();
        res.reserve(row*col);
        int cycle =min((row+1)/2, (col+1)/2);
        for(int i=0; i<cycle; i++)
        {
            for(int j=i; j<col-i; j++)
                res.push_back(matrix[i][j]);
            int k= col-1-i;
            for(int j=i+1; j<row-1-i; j++)
                res.push_back(matrix[j][k]);
            
            k = row-1-i;
            if(k<=i)
                continue;
            
            for(int j= col-1-i; j>=i; j--)
                res.push_back(matrix[k][j]);
            k = i;
            if(k >=col-1-i)
                continue;
            for(int j=row-2-i; j>i; j--)
                res.push_back(matrix[j][k]);
        }

        return res;
    }
};