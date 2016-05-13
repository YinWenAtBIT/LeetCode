class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k ==0)
            return false;
        int len = nums.size();
        unordered_set<int> save;
        for(int i=0; i<len; i++)
        {
            if(i>k)
            {
                int before = nums[i-k-1];
                auto it = save.find(before);
                save.erase(it);
            }
            auto res = save.insert(nums[i]);
            if(res.second == false)
                return true;
        }
        return false;
    }
};