class Solution {
public: 
	int maxProfit(int k, vector<int> &prices) { 
		int len = prices.size(); 
		if (len<2) 
			return 0; 
		if (k>len/2){ 
			// simple case 
			int ans = 0; 
			for (int i=1; i<len; ++i){ 
				ans += max(prices[i] - prices[i-1],0); 
			} 
			return ans; 
		} 
		int hold[k+1]; 
		int sell[k+1]; 
		for (int i=0;i<=k;++i){ 
			hold[i] = INT_MIN; 
			sell[i] = 0; 
		} 
		int cur; 
		for (int i=0; i<len; ++i){ 
			cur = prices[i]; 
			for(int j=1; j<=k; ++j){ 
			    hold[j] = max(hold[j],sell[j-1] - cur); 
				sell[j] = max(sell[j],hold[j] + cur); 
			} 
		} 
		return sell[k]; 
	} 
};
