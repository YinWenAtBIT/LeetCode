class Solution {  
public:  
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {  
        if(nums1.size()==0 || nums2.size()==0) return vector<int>();  
        vector<int> result;  
        unordered_map<int, int> hash;  
        for(auto val: nums1) hash[val]++;  
        for(auto val: nums2)  
        {  
            if(hash.count(val) && hash[val]>0) result.push_back(val);  
            hash[val]--;  
        }  
        return result;  
    }  
};  