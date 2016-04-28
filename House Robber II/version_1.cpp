class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len<1)
            return 0;
        if(len ==1)
            return nums[0];
        if(len ==2)
            return max(nums[0], nums[1]);
        int max_with_0 = nums[0];
        int max_now=0, take=0, notake=0;
        for(int i=2; i<len-1; i++)
        {
            take = notake+nums[i];
            notake = max_now;
            max_now = max(take, notake);
        }
        max_with_0 +=max_now;
        
        take=0, notake=0, max_now=0;
        for(int i=1; i<len; i++)
        {
            take = notake+nums[i];
            notake = max_now;
            max_now = max(take, notake);
        }
        return max(max_now, max_with_0);
    }
};