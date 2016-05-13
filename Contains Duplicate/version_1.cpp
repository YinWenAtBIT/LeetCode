class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> other;
        for(auto it = nums.begin(); it!= nums.end(); it++)
            other.insert(*it);
        return !(other.size()==nums.size());
    }
};