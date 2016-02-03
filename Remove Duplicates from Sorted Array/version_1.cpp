class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return 0;
        int pos=0;
        for(int i=1; i<len; i++)
        {
            if(nums[i] != nums[pos])
                nums[++pos] = nums[i];
        }
        return pos+1;
    }
};