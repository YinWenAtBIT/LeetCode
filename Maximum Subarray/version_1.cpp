class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len =nums.size();
        if(!len)
            return 0;
        
        int max = 0x80000000;
        int temp=0;
        for(int i=0; i<len; i++)
        {
            temp +=nums[i];
            if(temp>max)
                max  =temp;
            if(temp<0)
                temp =0;
        }
        return max;
    }
};