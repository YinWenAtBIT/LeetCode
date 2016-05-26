class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        row = matrix.size();
        if(!row)
            return false;
        col = matrix[0].size();
        int x=0, y=col-1;
        while(true)
        {
            if(matrix[x][y] == target)
                return true;
            if(matrix[x][y]>target)
                y -=1;
            else
                x +=1;
            if(!valid(x,y))
                break;
            
        }
        return false;
    }
    bool valid(int x, int y)
    {
        return (x>=0 && x<row && y>=0 && y<col);
    }
private:
    int row, col;
};