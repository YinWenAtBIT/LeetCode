class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        int len = nums.size();
        int max = 0;
        int i=0;
        for(i =0; i<len; i++)
        {
            if(abs(nums[i]) >max)
                max = abs(nums[i]);
        }
        
        if(abs(target) > max)
            max = abs(target);
            
        int max_1 = max+1;
        int max_1_2 = max_1+ max_1;
        int max_1_3 = max_1+max_1_2;
        int * hash = new int[max_1_3];
        int * numcount_pos = &hash[max_1];
        int * numcount_minus = &hash[max_1_2];
        
        for(i = 0; i<max_1; i++)
        {
            hash[i] =0;
            numcount_pos[i] = max_1;
            numcount_minus[i] = max_1;
        }
            
        
        
        int abs_target = abs(target);
        int abs_temp =0;
        int abs_rev_temp = 0;
        
        for(i =0; i<len; i++)
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
                if(numcount_pos[abs_temp] != max_1)
                {
                    if(nums[i] + nums[numcount_pos[abs_temp]] == target)
                    {
                        result[0] = numcount_pos[abs_temp] +1;
                        result[1] = i +1;
                        break;
                    }
                }
                
                if(numcount_minus[abs_temp] != max_1)
                {
                    if(nums[i] + nums[numcount_minus[abs_temp]] == target)
                    {
                        result[0] = numcount_minus[abs_temp] +1;
                        result[1] = i +1;
                        break;
                    }    
                }

                if(numcount_pos[abs_rev_temp] != max_1)
                {
                    if(nums[i] + nums[numcount_pos[abs_rev_temp]] == target)
                    {
                        result[0] = numcount_pos[abs_rev_temp] +1;
                        result[1] = i +1;
                        break;
                    }
                }
                
                if(numcount_minus[abs_rev_temp] != max_1)
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
        delete hash;
        return result;
    }
};