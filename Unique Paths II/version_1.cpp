class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        if(!m)
            return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1);
        for(int i=0; i<m+1; i++)
            dp[i].assign(n+1, 1);
        
        for(int i=0; i<m; i++)
            if(obstacleGrid[i][0] || dp[i][1] ==0)
                dp[i+1][1] = 0;
                
        for(int i=0; i<n; i++)
            if(obstacleGrid[0][i] || dp[1][i] ==0)
                dp[1][1+i] = 0; 
                
        for(int i=2; i<m+1; i++)
            for(int j=2; j<n+1; j++)
                if(obstacleGrid[i-1][j-1])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m][n];
    }
};