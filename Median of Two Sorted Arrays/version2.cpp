class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if((len1+len2)%2)
        {
            return find_topk(nums1, 0, nums2, 0, (len1+len2+1)/2);
        }
        else
        {
            return 0.5*(find_topk(nums1, 0, nums2, 0, (len1+len2)/2)
                            +find_topk(nums1, 0, nums2, 0, (len1+len2)/2+ 1));
        }
    }
    
    double find_topk(vector<int>& nums1, int l_shift, vector<int>& nums2, int r_shift, int topk)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();        
        if((len1-l_shift) > (len2-r_shift))
            return  find_topk(nums2, r_shift, nums1, l_shift, topk);
        
        if(!(len1 - l_shift))
            return double(nums2[r_shift+topk-1]);
        
        if(topk == 1)
            return double(min(nums1[l_shift], nums2[r_shift]));
        
        int amid = min((len1 - l_shift), topk/2);
        int bmid = topk- amid;
        
        if(nums1[l_shift+amid -1] < nums2[r_shift +bmid-1])
            return find_topk(nums1, l_shift+amid, nums2, r_shift, topk-amid);
        if(nums1[l_shift+amid -1] > nums2[r_shift +bmid-1])
            return find_topk(nums1, l_shift, nums2, r_shift + bmid, topk-bmid);
        else
            return double(nums1[l_shift+amid -1]);
        
    }
};