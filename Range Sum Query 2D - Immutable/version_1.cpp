class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        if(!row)
            return;
        int col = matrix[0].size();
        for(int i=0; i<row; i++)
        {
            vector<int> temp;
            temp.push_back(0);
            for(int j=0; j<col; j++)
                temp.push_back(temp.back()+matrix[i][j]);
            sum.push_back(temp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res =0;
        for(int i=row1; i<=row2; i++)
            res += sum[i][col2+1] - sum[i][col1];
        return res;
    }
private:
    vector<vector<int>> sum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);