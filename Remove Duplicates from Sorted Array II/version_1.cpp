class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len<3)
            return len;
        int pos = 1;
        for(int i=2; i<len; i++)
            if(nums[i] != nums[pos] || nums[i] != nums[pos-1])
                nums[++pos] = nums[i];
                
        return pos+1;
    }
};