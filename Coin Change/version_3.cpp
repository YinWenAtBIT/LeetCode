class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount+1, -1);
        dp[0] =0;
        
        for(int i=1; i<amount+1; i++)
        {
			int min_now = INT_MAX;
            for(int k=0; k<coins.size(); k++)
            {
                if(i>=coins[k] && dp[i-coins[k]] != -1)
					min_now = min(min_now, dp[i-coins[k]]+1);
            }
			dp[i] = min_now == INT_MAX? -1:min_now;
            
        }
        return dp[amount];
    }
};