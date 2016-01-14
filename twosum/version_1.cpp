class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result(2);
        int flag = 0;
        for(int i =0; i< len -1; i++)
        {
            for(int j = i+1; j< len; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    result[0] = i+1;
                    result[1] = j+1;
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 1)
                break;
                
        }
        
        return result;
    }
};