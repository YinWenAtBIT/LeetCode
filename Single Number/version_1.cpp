class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};