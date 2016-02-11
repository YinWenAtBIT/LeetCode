class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return 0;
           
       
        return jump_count(nums, 0);
    }
   
    int jump_count(vector<int>& nums, int pos)
    {
        int len = nums.size();
        int jump_len = nums[pos];
       
        if(jump_len+pos >= len-1)
            return 1;
           
        int min = 0x7fffffff;
        for(int j=jump_len; j>0; j--)
        {
            int temp = jump_count(nums, pos+j);
            if(temp<min)
                min = temp;
        }
        return  min+1;
    }
};