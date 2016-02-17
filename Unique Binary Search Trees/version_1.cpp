class Solution {
public:
    int numTrees(int n) {
        if(n<2)
            return 1;
        vector<int> dp(n+1);
        dp[0] = dp[1] =1;
        int sum =0;
        for(int i =2; i<=n; i++)
        {
            sum =0;
            for(int j = 1; j<=i; j++)
                sum += dp[j-1]*dp[i-j];
            dp[i] = sum;
        }
        return dp[n];
    }
};