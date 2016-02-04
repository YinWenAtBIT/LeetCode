class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(!len)
            return -1;
        return search_target(nums, target, 0, len -1);
        
    }
    int search_target(vector<int>&nums, int target, int left, int right)
    {
        if(left == right)
            return nums[left] == target? left:-1;
        
        if(left+1 == right)
        {
            if(nums[left] == target)
                return left;
            if(nums[right] == target)
                return right;
            
            return -1;
        }
        
        
        int center = (left+right)/2;
        
        if(target == nums[center])
            return center;
        
        bool sorted=false;
        if(nums[left]<nums[center] && nums[center]<nums[right])
            sorted = true;
        
        if(sorted)
        {
            if(nums[center] == target)
                return center;
            if(target< nums[center])
                return search_target(nums, target, left, center);
            else
                return search_target(nums, target, center+1, right);
        }
        
        bool center_to_before  = nums[center]>nums[left]? true:false;
        if(center_to_before)
        {
            if(nums[center] == target)
                return center;
                
            if(target< nums[center])
            {
                if(target >= nums[left])
                    return search_target(nums, target, left, center);
                else
                    return search_target(nums, target, center+1, right);
            }
            else
                return search_target(nums, target, center+1, right);
        }
        else
        {
             if(nums[center] == target)
                return center;
                
            if(target < nums[center])
                return search_target(nums, target, left, center);
            else
            {
                if(target<= nums[right])
                    return search_target(nums, target, center+1, right);
                else
                    return search_target(nums, target, left, center);
            }
            
        }
    }
};