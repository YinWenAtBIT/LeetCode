class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        int len = nums.size();
        int max = 0;
        
        for(int i =0; i<len; i++)
        {
            if(abs(nums[i]) >max)
                max = abs(nums[i]);
        }
        
        if(abs(target) > max)
            max = abs(target);
            
        vector<int> hash(max+1, 0);
        
        vector<int> numcount_pos (max+1, max+1);
        vector<int> numcount_minus (max+1, max+1);
        
        int abs_target = abs(target);
        int abs_temp =0;
        int abs_rev_temp = 0;
        
        for(int i =0; i<len; i++)
        {
            abs_temp = abs(nums[i]);
            abs_rev_temp = abs(abs_target - abs_temp);
            
            if(hash[abs_temp] == 0 && hash[abs_rev_temp] == 0)
            {
                
                hash[abs_temp] = 1;
                if( nums[i] <0)
                    numcount_minus[abs_temp] = i;
                else
                    numcount_pos[abs_temp] = i;
                
            }
            
            else
            {
                if(numcount_pos[abs_temp] != max+1)
                {
                    if(nums[i] + nums[numcount_pos[abs_temp]] == target)
                    {
                        result[0] = numcount_pos[abs_temp] +1;
                        result[1] = i +1;
                        break;
                    }
                }
                
                if(numcount_minus[abs_temp] != max+1)
                {
                    if(nums[i] + nums[numcount_minus[abs_temp]] == target)
                    {
                        result[0] = numcount_minus[abs_temp] +1;
                        result[1] = i +1;
                        break;
                    }    
                }

                if(numcount_pos[abs_rev_temp] != max+1)
                {
                    if(nums[i] + nums[numcount_pos[abs_rev_temp]] == target)
                    {
                        result[0] = numcount_pos[abs_rev_temp] +1;
                        result[1] = i +1;
                        break;
                    }
                }
                
                if(numcount_minus[abs_rev_temp] != max+1)
                {
                    if(nums[i] + nums[numcount_minus[abs_rev_temp]] == target)
                    {
                        result[0] = numcount_minus[abs_rev_temp] +1;
                        result[1] = i +1;
                        break;
                    }
                }
            }
             
        }
        
        return result;
    }
};