class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
  
        vector<int> dp(len, 1);
        for(int i=1; i<len; i++)
        {
            int max_temp =1;
            for(int j=0; j<i; j++)
            {
                int temp =0;
                if(nums[i]>nums[j])
                    temp = dp[j]+1;

                if(temp>max_temp)
                    max_temp = temp;
            }
            dp[i] = max_temp;
        }
        int max_now =0;
        for(int i=0; i<len; i++)
            if(dp[i]>max_now)
                max_now = dp[i];
        return max_now;
    }

};