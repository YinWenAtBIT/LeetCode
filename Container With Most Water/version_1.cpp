class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_contain =0;
        for(int i=0; i< len -1; i++)
            for(int j = i+1; j< len; j++)
            {
                int contain = min(height[i], height[j])*(j-i);
                if(contain> max_contain)
                    max_contain = contain;
            }
        return max_contain;
    }
};