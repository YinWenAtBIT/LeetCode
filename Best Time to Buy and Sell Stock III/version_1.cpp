class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <2)
            return 0;
        int sum = 0;
        vector<int> from_begin(len, 0);
        
        int min_pri = prices[0];
        int ans =0;
        for(int i=0; i<len; i++)
        {
            if(prices[i] - min_pri>ans)
                ans = prices[i] - min_pri;

            if(prices[i]< min_pri)
                min_pri = prices[i];
            
            from_begin[i] = ans;
        }
        
        vector<int> from_end(len, 0);
        ans =0;
        int high = prices[len-1];
        for(int i= len-1; i>=0; i--)
        {
            if(high - prices[i]>ans)
                ans = high-prices[i];
            if(prices[i]>high)
                high = prices[i];
            from_end[i] = ans;
        }
        for(int i=0; i<len; i++)
        {
            if(sum<from_begin[i]+ from_end[i])
                sum = from_begin[i]+ from_end[i];
        }
        return sum;
    }
};