class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
            
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0) {
                    break;
                }
                swap(nums[i], nums[ nums[i] - 1 ]);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return 0;
    }
};