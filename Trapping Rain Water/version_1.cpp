class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len<3)
            return 0;
        int left_index, left_height;
        for(int i=0; i<len; i++)
        {
            if(height[i])
            {
                left_index= i;
                left_height = height[i];
                break;
            }
        }
        
        int contain = 0;
        vector<int> avalible(len,0);
        for(int i=left_index; i<len; i++)
        {
            if(height[i]<left_height)
            {
                avalible[i] = left_height-height[i];
                if(height[i]>height[i-1])
                {
                    for(int j = left_index+1; j<i; j++)
                    {
                        if(avalible[j]>avalible[i])
                        {
                            contain += avalible[j] - avalible[i];
                            avalible[j] = avalible[i];
                        }
                    }
                }

            }
            else
            {
                for(int j = left_index+1; j<i; j++)
                    contain+= avalible[j];
                    
                left_index = i;
                left_height = height[i];
            }
        }
        
        return contain;
    }
};