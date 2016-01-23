class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int flag = (len1+len2)%2;
        if(flag)
        {
            return find_topk(nums1, 0, nums2, 0, (len1+len2+1)/2 , flag);
        }
        else
        {
            return find_topk(nums1, 0, nums2, 0, (len1+len2)/2, flag);
        }
    }
    
    double find_topk(vector<int>& nums1, int l_shift, vector<int>& nums2, int r_shift, int topk, int flag)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();        
        if((len1-l_shift) > (len2-r_shift))
            return  find_topk(nums2, r_shift, nums1, l_shift, topk, flag);
        
        if(!(len1 - l_shift))
            if(flag)
                return double(nums2[r_shift+topk-1]);
            else
                return 0.5*(nums2[r_shift+topk-1] + nums2[r_shift+topk]);
        
        if(topk == 1)
        {
            if(flag)
                return double(min(nums1[l_shift], nums2[r_shift]));
            else
            {
                if(len1 - l_shift == 1 & len2 - r_shift ==1)
                    return 0.5*(nums1[l_shift] + nums2[r_shift]);
                
                if(nums1[l_shift] < nums2[r_shift])
                {
                    if(len1 - l_shift == 1)
                        return 0.5*(nums1[l_shift] + nums2[r_shift]);
                    else
                        return 0.5*(nums1[l_shift] + min(nums1[l_shift+1], nums2[r_shift]));
                }
                else
                {
                    if(len2 - r_shift == 1)
                        return 0.5*(nums1[l_shift] + nums2[r_shift]);
                    else
                        return 0.5*(nums2[r_shift] + min(nums1[l_shift], nums2[r_shift+1]));                    
                }
            }
        }
        int amid = min((len1 - l_shift), topk/2);
        int bmid = topk- amid;
        
        if(nums1[l_shift+amid -1] < nums2[r_shift +bmid-1])
            return find_topk(nums1, l_shift+amid, nums2, r_shift, topk-amid, flag);
        if(nums1[l_shift+amid -1] > nums2[r_shift +bmid-1])
            return find_topk(nums1, l_shift, nums2, r_shift + bmid, topk-bmid, flag);
        else
        {
            if(flag)
                return double(nums1[l_shift+amid -1]);
            else
            {
                if(len1 -l_shift>1 & len2 - r_shift>1)
                    return 0.5*(nums1[l_shift+amid -1] + min(nums1[l_shift+amid], nums2[r_shift+bmid]));
                if(len1-l_shift>1)
                    return 0.5*(nums1[l_shift+amid -1] + nums1[l_shift+amid]);
                else
                    return 0.5*(nums1[l_shift+amid -1] + nums2[r_shift+bmid]);
            }
        }
        
    }
};