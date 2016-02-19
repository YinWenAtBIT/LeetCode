class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(!numRows)
            return res;
        vector<int> temp(1,1);
        res.push_back(temp);
        for(int i=2; i<=numRows; i++)
        {
            temp.assign(i,1);
            for(int j=1; j<i-1; j++)
                temp[j] = res[i-2][j-1]+res[i-2][j];
            res.push_back(temp);
        }
        return res;
    }
};