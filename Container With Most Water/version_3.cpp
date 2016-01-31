class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int max_contain =0;
        int left=0;
        int right = len-1;
        while(left != right)
        {
            int contain  = min(height[left], height[right])*(right-left);
            if(contain > max_contain)
                max_contain = contain;
            if(height[left]< height[right])
                left++;
            else
                right--;
        }

        return max_contain;
    }
};