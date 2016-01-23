class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1= nums1.size();
        int len2 = nums2.size();
        int half = (len1+len2)/2;
        bool flag =false;
        int count_all;
        int last;
        if(2*half == (len1+len2))
        {
            flag =false;
            count_all = half;
        }
        else
        {
            flag =true;
            count_all =  half+1;
        }
        
        int index1=0, index2 =0;
        while(index1 <len1 & index2 <len2 && count_all)
        {
            if(nums1[index1]< nums2[index2])
            {
                last = nums1[index1];
                ++index1;
            }
            else
            {
                last = nums2[index2];
                ++index2;
            }
            
            --count_all;
        }
        
        if(count_all)
        {
            if(index1 == len1)
            {
                while(count_all)
                {
                    ++index2;
                    --count_all;
                }
                last = nums2[index2-1];
            }
            else
            {
                while(count_all)
                {
                    ++index1;
                    --count_all;
                }
                last = nums1[index1-1];
            }
        }
        
        
        if(flag)
            return double(last);
        else
        {
            if(index1 <len1 & index2 <len2)
                return (last+min(nums1[index1], nums2[index2]))/2.0;
            
            if(index1 <len1)
                return (last + nums1[index1])/2.0;
            else
                return (last + nums2[index2])/2.0;
        }
        
    }
};