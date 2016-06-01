class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res;
        
        int start1 = 0, start2 =0;
        int end1, end2;
        while(k)
        {
            int total = len1- start1+len2-start2;
            int choice = total - k;
            end1 = start1 +choice+1;
            end2 = start2 +choice+1;
            int now = find_max(nums1, nums2, start1, end1, start2, end2);
            res.push_back(now);
            k--;
        }
        return res;
    }
    int find_max(vector<int>& nums1, vector<int>& nums2, int &start1, int end1, int &start2, int end2)
    {
        int index1, index2;
        bool use2 = false;
        int max_now = INT_MIN;
        for(int i = start1; i<end1 && i<nums1.size(); i++)
            if(nums1[i]>max_now)
            {
                max_now = nums1[i];
                index1 = i;
            }

        for(int i = start2; i<end2 && i<nums2.size(); i++)
            if(nums2[i]>max_now)
            {
                max_now = nums2[i];
                index2 = i;
                use2 = true;
            }        
            
        if(use2)
            start2 = index2+1;
        else
            start1 = index1+1;
            
        return max_now;
    }
};