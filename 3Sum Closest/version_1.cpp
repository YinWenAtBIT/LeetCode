class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int closet= 0x7fffffff;
        int res=0;
        
        for(int i=0; i<len-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int temp = two_closet(nums, i+1, target - nums[i]);
            int new_closet = abs(target- temp-nums[i]);
            if( new_closet< closet)
            {
                closet = new_closet;
                res = temp+nums[i];
                if(res == target)
                    return target;
            }
        }
        return res;
    }
    int two_closet(vector<int>& nums, int start, int target)
    {
        int left = start;
        int right = nums.size()-1;
        int closet= 0x7fffffff;
        int res;
        int temp;
        while(left<right)
        {
            temp = nums[left] + nums[right];
            int new_closet = abs(target -temp);
            if( new_closet< closet)
            {
                closet = new_closet;
                res = temp;
                if(res == target)
                    return target;
            }
            if(temp>target)
                right--;
            else
                left++;
        }
        return res;
    }
    
};