class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len<=2*k)
            return make_max(prices);
            
        vector<vector<int>> dp(len);
        for(int i=0; i<len; i++)
            dp[i].assign(len, 0);
        
        for(int l=1; l<len -2*k+2; l++)
            for(int i=0; i+l <len; i++)
                dp[i][i+l] = make_one(prices, i, i+l);
        
        int max_pro =0;
        dfs(dp, 0, k, 0, max_pro);
        
        return max_pro;
        
    }
    
    void dfs(vector<vector<int>> &dp, int start, int count, int sum, int &max_pro)
    {
        int len = dp.size();
        if((start >= len-1 || count ==0) && sum >max_pro)
        {
            max_pro = sum;
            return;
        }
        for(int i=start+1; i<len; i++)
        {
            sum += dp[start][i];
            dfs(dp, i+1, count-1, sum, max_pro);
            sum -= dp[start][i];
        }
    }
    
    int make_one(vector<int>& prices, int start, int end)
    {
        int min_pri = prices[start];
        int ans = 0;
        for(int i= start+1; i<=end; i++)
        {
            ans =max(ans, prices[i] - min_pri);
            min_pri = min(min_pri, prices[i]);
        }
        return ans;
    }
    
    int make_max(vector<int>& prices)
    {
        int len = prices.size();
        int ans =0;
        for(int i=1; i<len; i++)
            if(prices[i]- prices[i-1]>0)
                ans += prices[i]- prices[i-1];
        return ans;
    }
};