class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, -1);
        dp[0] =0;
        int now_min = INT_MAX;
        if(dfs(coins, amount, 0, len-1, now_min))
            return now_min; 
        return -1;
    }
    
    bool dfs(vector<int>& coins, int amount, int now_count, int now_use, int &now_min)
    {
        if(now_count>= now_min)
            return false;
        if(amount == 0)
        {
            now_min = now_count;
            return true;
        }
        
        bool flag =false;
        int len = coins.size();
        for(int i= now_use; i>=0; i--)
        {
            if( now_min != INT_MAX && (now_min - now_count)*coins[i] <amount)
                break;
            if(amount >= coins[i] && dfs(coins, amount-coins[i], now_count+1, i, now_min))
                flag = true;
            
        }
        return flag;
    }
};