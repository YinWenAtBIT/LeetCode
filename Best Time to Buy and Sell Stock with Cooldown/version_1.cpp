class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(!len)
            return 0;
        vector<int> one_best(len, 0);
        for(int i =1; i<len; i++)
            one_best[i] = get_one_best(prices, 0, i);
        
        vector<int> dp = one_best;
        for(int i=4; i<len; i++)
        {
            int max_temp;
            for(int j=1; j+2<i; j++)
            {
                int temp = dp[j] + get_one_best(prices, j+2, i);
                if(temp >max_temp)
                    max_temp = temp;
            }
            dp[i] = max(dp[i], max_temp);
        }
        return dp[len -1];
    } 
    int get_one_best(vector<int>& prices, int start, int end)
    {
        int min_pri = prices[start];
        int best = 0;
        for(int i= start+1; i<=end; i++)
        {
            best = max(best, prices[i] -min_pri);
            min_pri = min(min_pri, prices[i]);
        }
        return best;
    }
};