class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row)
            return false;
        int col = matrix[0].size();
        
        int start_pos = -1;
        for(int i=0; i<row; i++)
            if(matrix[i][0]<=target)
                start_pos = i;
            else
                break;
        
        if(start_pos == -1)
            return false;
        
        if(target> matrix[start_pos][col-1])
            return false;
        int left =0;
        int right = col-1;
        int mid;
        while(left<right)
        {
            mid= (left+right)/2;
            if(matrix[start_pos][mid]<target)
                left= mid+1;
            else
                right = mid;
        }
        return matrix[start_pos][left] == target;
    }
};