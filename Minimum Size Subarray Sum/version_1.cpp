class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        
        int sum =0;
        int left = 0;
        int right =0;
        int len_total= len+1;
        while(right<len)
        {
            while(sum<s && right<len)
            {
                sum +=nums[right];
                right++;
            }
            while(left<right && sum-nums[left]>=s)
            {
                sum -=nums[left];
                left++;
            }
            if(sum >= s)
                if(right-left <len_total)
                    len_total = right-left;
            
            sum -= nums[left];
            left++;
        }
        if(len_total == len+1)
            return 0;
        else
            return len_total;
    }
};