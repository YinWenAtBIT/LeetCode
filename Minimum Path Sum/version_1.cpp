class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m)
            return 0;
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1);
        for(int i=0; i<m+1; i++)
            dp[i].assign(n+1, 0);
            
        
        dp[1][1] = grid[0][0];
        for(int i=2; i<n+1; i++)
            dp[1][i] = dp[1][i-1]+grid[0][i-1];
        for(int i=2; i<m+1; i++)
            dp[i][1] = dp[i-1][1] +grid[i-1][0];
            
        for(int i=2; i<m+1; i++)
            for(int j=2; j<n+1; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        
        return dp[m][n];
    }
};