class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return -1;
        return find_peak(nums, 0, len-1);
        
    }
    int find_peak(vector<int>& nums, int left, int right)
    {
        int mid = (left+right)/2;
        int len = nums.size();
        bool l_lar = false;
        bool r_lar = false;
        if(mid -1<0 || nums[mid]>nums[mid-1])
            l_lar = true;
        if(mid+1>=len || nums[mid]>nums[mid+1])
            r_lar = true;
        if(l_lar && r_lar)
            return mid;
        if(l_lar)
            return find_peak(nums, mid+1, right);
        else
            return find_peak(nums, left, mid);
    }
};