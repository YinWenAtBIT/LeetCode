class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else
            {
                if(nums[i] == candidate)
                    count ++;
                else
                    count --;
            }
        }
        return candidate;
    }
};