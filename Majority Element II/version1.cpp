class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int size = nums.size();
        int n1=0,n2=0,cn1=0,cn2=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==n1)
            {
                cn1++;
            }
            else if(nums[i]==n2)
            {
                cn2++;
            }
            else if(cn1==0)
            {
                n1 = nums[i];
                cn1 = 1;
            }
            else if(cn2==0)
            {
                n2 = nums[i];
                cn2 = 1;
            }
            else
            {
                cn1--;
                cn2--;
            }
        }
        if(cn2==0&&size>0)//用来解决[0 0]的情况
          n2=nums[0]-1;
        cn1=0;
        cn2=0;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==n1)
            cn1++;
            if(nums[i]==n2)
            cn2++;
        }
        if(cn1>size/3)
        v.push_back(n1);
        if(cn2>size/3)
        v.push_back(n2);
        return v;
    }
};