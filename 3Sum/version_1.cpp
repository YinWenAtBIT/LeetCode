class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now(3);
        vector<int> last(3,-1);
        
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int left = 0, right = len -1;
        while(right -left>1)
        {
            int temp = nums[left] + nums[right];
            if(temp + nums[left+1] <= 0 && temp + nums[right-1] >=0)
            {
                for(int i=left+1; i<right; i++)
                {
                    if(temp+ nums[i] == 0)
                    {
                        now[0] = nums[left];
                        now[1] = nums[i];
                        now[2] = nums[right];
                        if(now != last)
                        {
                            res.push_back(now);
                            last = now;
                            break;
                        }
                        else
                            break;
                    }
                    
                }
                right --;
            }
            else
            {
                if(temp + nums[left+1] >0)
                    --right;
                else
                    ++left;
            }
        }
        return res;
    }
};