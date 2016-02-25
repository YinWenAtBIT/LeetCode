class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(!len)    
            return 0;
        if (len == 1)
            return nums[0];

        int max_local = nums[0];
        int min_local = nums[0];
        int global = nums[0];
        for (int i = 1; i < len; ++ i) 
        {
            int max_copy = max_local;
            max_local = max(max(nums[i] * max_local, nums[i]), nums[i] * min_local);
            min_local = min(min(nums[i] * max_copy, nums[i]), nums[i] * min_local);
            global = max(global, max_local);
        }
        return global;
        
    }
};