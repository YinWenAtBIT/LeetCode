class Solution {
public:
    int numSquares(int n) {
        if(!n)
            return 0;
        vector<int> dp(n+1, n+1);
        dp[0] =0;
        dp[1] =1;
        for(int i =2; i<n+1; i++)
        {
            for(int j=1; j*j<=i; j++)
            {
                int res = i- j*j;
                dp[i] = min(dp[res]+1, dp[i]);
            }
        }
        return dp[n];
    }
};