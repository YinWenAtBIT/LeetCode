class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<2)
            return 0;
        int min_pri = prices[0];
        int ans =0;
        for(int i=0; i<len; i++)
        {
            ans = max(ans, prices[i] - min_pri);
            min_pri = min(min_pri, prices[i]);
        }
        return ans;
    }
};