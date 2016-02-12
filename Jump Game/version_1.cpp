class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return true;
        int cur=0;
        int max=0;
        int jump;
        while(cur<len-1)
        {
            int now = nums[cur];
            if(!now)
                return false;
            max =0;
            if(cur+now>len-2)
                break;
            for(int i=now; i>0; i--)
            {
                if(i+nums[cur+i]>max)
                {
                    max = i+nums[cur+i];
                    jump = i;
                }
            }
            cur= cur+jump;
        }
        return true;
    }
};