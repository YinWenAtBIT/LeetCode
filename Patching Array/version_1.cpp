class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, k = nums.size(), i = 0;
        while (miss <= n) {
            if (i >= nums.size() || nums[i] > miss) {
                nums.insert(nums.begin() + i, miss);
            }
            miss += nums[i++];
        }
        return nums.size() - k;
    }
};