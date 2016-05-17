class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int len = nums.size();
        set<int> save;
        for(int i=0; i<len; i++)
        {
            for(int j=i-1; j>=0 && i-j<=k; j--)
            {
                if(abs(nums[i]-nums[j]) <=t)
                    return true;
            }
        }
        return false;
    }
};