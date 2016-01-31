class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_contain =0;
        int left_height=0;
        int right_height =0;
        for(int i=0; i< len -1; i++)
        {
            if(height[i]< left_height)
                continue;
            
            for(int j=len-1; j>i; j--)
            {
                if(height[j]<right_height)
                    continue;
                    
                int contain = min(height[i], height[j])*(j-i);
                if(contain > max_contain)
                {
                    left_height = height[i];
                    right_height = height[j];
                    max_contain = contain;
                }
                
            }
        }
        return max_contain;
    }
};