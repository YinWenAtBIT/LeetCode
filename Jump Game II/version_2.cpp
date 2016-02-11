class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return 0;
           
        int count=0;
        int cur=0;
        int nextpos;
        int max_len;
        while(cur <len-1)
        {
            int jump_len = nums[cur];
            max_len =0;
            for(int i = jump_len; i>0; i--)
            {
                if(cur+i >=len -1)
                {
                    nextpos = cur+i;
                    break;
                }
                if(i+nums[cur+i] >max_len)
                {
                    max_len = i +nums[cur+i];
                    nextpos = cur+i;
                }
            }
           
            count++;
            cur = nextpos;
        }
        return count;
    }
};