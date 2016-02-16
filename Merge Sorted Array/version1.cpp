class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return;
        if(!m)
        {
            nums1 = nums2;
            return;
        }

        int left=m-1, right =n-1;
        int pos = m+n-1;
        while(left>=0 && right>=0)
        {
            if(nums1[left]>nums2[right])
                nums1[pos--] = nums1[left--];
            else
                nums1[pos--] = nums2[right--];
        }
        while(right>=0)
            nums1[pos--] = nums2[right--];
        return;
    }
};