class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return;
        vector<int> temp(len);
        Msort(nums, temp, 0, len-1);
    }
    
    void Msort(vector<int> &nums, vector<int> & temp, int left, int right)
    {
        if(left == right)
            return;
        int mid = (left+right)/2;
        Msort(nums, temp, left, mid);
        Msort(nums, temp, mid+1, right);
        
        Merge(nums, temp, left, mid+1, right);
    }
    
    void Merge(vector<int> &nums, vector<int> & temp, int left, int right, int right_end)
    {
        int left_end, N, start_pos;
        left_end = right-1;
        N= right_end - left+1;
        start_pos = left;
        while(left <= left_end && right <= right_end)
        {
            if(nums[left]<nums[right])
                temp[start_pos++] = nums[left++];
            else
                temp[start_pos++] = nums[right++];
        }
        while(left<= left_end)
            temp[start_pos++] = nums[left++];
            
        while(right <= right_end)
            temp[start_pos++] = nums[right++];
            
        for(int i=0; i<N; i++)
        {
            nums[right_end] =  temp[right_end];
            right_end--;
        }
            
    }
};