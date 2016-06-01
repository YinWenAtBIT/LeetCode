class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        for(int i=1; i<len; i++)
            if((i%2 && nums[i] <nums[i-1]) || (!(i%2) && nums[i] >nums[i-1]))
                swap(nums[i], nums[i-1]);
    }
};