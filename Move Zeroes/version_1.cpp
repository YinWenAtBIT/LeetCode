class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int count =0;
        int total =0;
        for(int i=len-1; i>=0; i--)
        {
            count =0;
            while(i>=0 &&nums[i] == 0)
            {
                count++;
                i--;
            }
            if(count)
            {
                total+=count;
                memmove(nums.data()+i+1, nums.data()+i+count+1, (len-count-i-1)*sizeof(int));
            }
        }
        for(int i=len-1; total>0; total--, i--)
            nums[i] =0;
    }
};