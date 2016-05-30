class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return 0;
        
        vector<int> sub(len, 0);
        vector<vector<int>> dp(len, sub);
        for(int i =0; i<len-1; i++)
        {
            if(nums[i]<nums[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 0;
        }
        for(int k=2; k<len; k++)
        {
            for(int i=0; i+k<len; i++)
            {
                int max_temp =0;
                for(int j=i+1; j<i+k; j++)
                {
                    int temp;
                    if(dp[i][j] && dp[j][i+k])
                        temp = dp[i][j]+dp[j][i+k]-1;
                    else
                        temp = max(dp[i][j],dp[j][i+k]);
                    if(temp >max_temp)
                        max_temp = temp;
                }
                dp[i][i+k] = max_temp;
            }
        }
        return dp[0][len-1];
    }
};