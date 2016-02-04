class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left =0;
        int len = nums.size();
        int right = nums.size()-1;
        int center;
        
        int left_index =-1, right_index = -1;
        while(left<= right)
        {
            center = (left+right)/2;
            if(nums[center] == target)
            {
                left_index= right_index =center;
                
                int left_mid = left_index;
                int left_end = center;
                while(left<= left_end)
                {
                    left_mid = (left+left_end)/2;
                    if(nums[left_mid] == target)
                    {
                        left_end = left_mid-1;
                        if(left_mid <left_index)
                            left_index = left_mid;
                            
                    }
                    else
                        left = left_mid+1;
                }
                
                int right_mid = right_index;
                int right_end = center;
                while(right_end<=right)
                {
                    right_mid = (right_end+right)/2;
                    if(nums[right_mid] == target)
                    {
                        right_end = right_mid +1;
                        if(right_mid >right_index)
                            right_index = right_mid;
                    }
                    else
                        right = right_mid-1;
                }
                break;
            }
            
            if(nums[center]< target)
                left= center+1;
            else
                right = center -1;
                
        }
        vector<int> res;
        res.push_back(left_index);
        res.push_back(right_index);
        return res;
        
    }
};