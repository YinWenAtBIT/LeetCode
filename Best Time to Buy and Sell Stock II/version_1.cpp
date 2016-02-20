class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<2)
            return 0;
            
        int sum =0;
        bool flag = false;
        int buyprice =0;
        for(int i=0; i<len; i++)
        {

            if(!flag && i<len-1 && prices[i] < prices[i+1])
            {
                flag = true;
                buyprice = prices[i];
            }
            
            if(flag)
            {
                if(i == len-1)
                {
                    sum += prices[i] - buyprice;
                    flag = false;
                }
                else if(prices[i] > prices[i+1])
                {
                    sum += prices[i] - buyprice;
                    flag = false;
                }
            }
        
        }
        return sum;
    }
};