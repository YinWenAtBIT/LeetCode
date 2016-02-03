class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int pos =0;
        for(int i=len-1; i>=0; i--)
        {
            if(nums[i] == val)
            {
                nums[i] =  nums[len -1];
                len --;
            }
        }
        return len;
    }
};