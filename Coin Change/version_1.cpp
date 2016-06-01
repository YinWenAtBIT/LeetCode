class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] =0;
        
        for(int i=1; i<amount+1; i++)
        {
            for(int j= i-1; j>=0; j--)
            {
                if(dp[j] == -1)
                    continue;
                for(int k=0; k<coins.size(); k++)
                {
                    if(coins[k] +j == i)
                        dp[i] = dp[j] +1;
                    else if(coins[k]+j>i)
                        break;
                }
            }
        }
        return dp[amount];
    }
};