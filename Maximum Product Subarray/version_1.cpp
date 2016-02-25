class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(!len)    
            return 0;
        vector<vector<int>> dp(len);
        int ma = 0x80000000;
        for(int i=0; i<len; i++)
        {
            dp[i].assign(len, 0);
            dp[i][i] = nums[i];
            if(nums[i]>ma)
                ma = nums[i];
        }
        for(int i=0; i<len; i++)
            for(int j=i+1; j<len; j++)
            {
                dp[i][j] = dp[i][j-1]*nums[j];
                if(dp[i][j]>ma)
                    ma = dp[i][j];
            }
        return ma;
        
    }
};