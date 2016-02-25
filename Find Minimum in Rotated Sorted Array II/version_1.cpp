class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        return min_search(nums, 0, len-1);
    }
    int min_search(vector<int> &nums, int left, int right)
    {
        if(left == right)
            return nums[left];
        if(right -left == 1)
            return min(nums[left], nums[right]);
        while(left+1<right)
        {
            int mid = (left+right)/2;
            if(nums[mid] > nums[left])
            {
                if(nums[mid] >nums[right])
                    return min_search(nums, mid+1, right);
                else
                    return nums[left];
            }
            else if(nums[mid] <nums[left])
            {
                return min_search(nums, left+1, mid);
            }
            else
                left++;
        }
        return min(nums[left], nums[right]);
    }
};