class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<2)
            return 0;
        vector<int> buy_pri(len);
        vector<int> sell_pri(len);
        buy_pri[0] = prices[0];
        sell_pri[len-1] = prices[len-1];
        for(int i =1; i<len; i++)
        {
            buy_pri[i] = min(buy_pri[i-1], prices[i]);
            sell_pri[len-1-i] = max(sell_pri[len-i], prices[len-1-i]);
        }
        int profit= 0;
        for(int i=0; i<len; i++)
            if(profit<sell_pri[i] - buy_pri[i])
                profit = sell_pri[i] - buy_pri[i];
        return profit;
    }
};