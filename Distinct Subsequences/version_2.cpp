class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        vector<vector<int>> dp(len_s+1);
        for(int i=0; i<len_s+1; i++)
        {
            dp[i].assign(len_t+1, 0);
            dp[i][0] =1;
        }
        for(int i=1; i<len_s+1; i++)
            for(int j=1; j<len_t+1; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        
        return dp[len_s][len_t];
    }
};