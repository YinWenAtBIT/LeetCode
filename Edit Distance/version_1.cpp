class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1);
        for(int i=0; i<m+1; i++)
            dp[i].resize(n+1);
        
        for(int i=0; i<n+1; i++)
            dp[0][i] = i;
        for(int i=0; i<m+1; i++)
            dp[i][0] = i;
          
          
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                int way_1 = dp[i-1][j]+1;
                int way_2 = dp[i][j-1]+1;
                int way_3 = dp[i-1][j-1] + (word1[i-1]== word2[j-1]?0:1);
                dp[i][j] = min(way_1, min(way_2, way_3));
            }
        return dp[m][n];
    }
};