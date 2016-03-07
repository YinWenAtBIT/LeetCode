class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k%len;
        if(k ==0)
            return;
        vector<int> sub(nums.end()-k, nums.end());
        for(int i=len-k-1; i>=0; i--)
            nums[i+k] = nums[i];
        for(int i=0; i<k; i++)
            nums[i] = sub[i];
        
    }
};