class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len)
            return 0;
        
        int left =0, right = len-1;
        int mid;
        while(left<right)
        {
            mid = (left+right)/2;
            if(nums[mid]<target)
                left = mid+1;
            else
                right = mid;
        }
        if(nums[left]<target)
            return left+1;
        return left;
    }
};