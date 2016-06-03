class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        unordered_set<int> save;
        for(int i=0; i<len1; i++)
            save.insert(nums1[i]);
        
        unordered_set<int> out;
        for(int i=0; i<len2; i++)
            if(save.count(nums2[i]))
                out.insert(nums2[i]);
            
        vector<int> res(out.begin(), out.end());
        return res;
    }
};