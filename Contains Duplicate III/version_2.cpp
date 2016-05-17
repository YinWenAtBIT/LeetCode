class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k<1 || t<0)
            return false;
        int len = nums.size();
        if(len<1)
            return false;
            
        set<int> save;
        save.insert(nums[0]);
        for(int i=1; i<len; i++)
        {
            long long int min_dif = find_min(save, nums[i]);
            if(abs(min_dif)<=t)
                return true;
            
            if(i>=k)
                save.erase(nums[i-k]);
            save.insert(nums[i]);
        }
        return false;
    }
    
    int find_min(set<int> & save, long long int num)
    {
        auto it = save.lower_bound(num);
        long long int min_dif = 9223372036854775807;
        if(it != save.end())
        {
            min_dif = *it - num;
        }
        if(it != save.begin())
        {
            it--;
            min_dif = min(min_dif, num -*it);
        }
        return min_dif;
    }
    
    
};