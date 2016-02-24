class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int One = 0, Two = 0, Three = 0;
        for (int i = 0; i < n; i++) {
            Two |= (One & nums[i]);
            One ^= nums[i];
            Three = One & Two;
            One &= (~Three);
            Two &= (~Three);
        }
        return One;
    }
};