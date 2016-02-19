class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(!row)
            return 0;
        vector<int> dp(row, triangle[0][0]);
        for(int i=2; i<=row; i++)
        {
            int first = dp[0];
            int second =dp[0];
            for(int j =0; j<i; j++)
            {
                first = second;
                second = dp[j];
                if(j == i-1)
                    dp[j] = first +triangle[i-1][j];
                else
                    dp[j] = min(first, second) + triangle[i-1][j];
            }
        }
        int ret = 0x7fffffff;
        for(int i=0; i<row; i++)
            if(ret> dp[i])
                ret = dp[i];
        return ret;
    }
};