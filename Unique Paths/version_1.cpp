class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1);
        for(int i=0; i<m+1; i++)
            dp[i].assign(n+1, 1);
        for(int i=2; i<m+1; i++)
            for(int j = 2; j<n+1; j++)
                dp[i][j] = dp[i-1][j] +dp[i][j-1];
        
        return dp[m][n];
    }
};