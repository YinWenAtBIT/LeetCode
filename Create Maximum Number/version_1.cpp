class Solution {  
public:  
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {  
        int size1 = nums1.size();  
        int size2 = nums2.size();  
        vector<int> res(k);  
        vector<int> tmp(k);  
        for (int i = 0; i <= k; i++)  
        {  
            if (k - i > size2)  continue;  
            if (i > size1)        break;  
            vector<int> num1;  
            vector<int> num2;  
            num1 = getnum(nums1, i);  
            num2 = getnum(nums2, k - i);  
            tmp = mergenum(num1, num2);  
            res = cmp(res, tmp);  
        }  
        return res;  
    }  
    vector<int> getnum(vector<int>& num, int n)  
    {  
        vector<int> vec;    
        int drop = num.size()-n;    
        for(int i =0; i< num.size(); i++)    
        {    
            while(drop >0 && vec.size() && num[i] > vec.back())    
            {    
                drop--;    
                vec.pop_back();    
            }    
            vec.push_back(num[i]);    
        }    
        vec.resize(n);    
        return vec;    
  
          
    }  
    vector<int> mergenum(vector<int> & num1, vector<int> & num2)  
    {  
        vector<int> vec;    
        while(num1.size() + num2.size() > 0)    
        {    
            vector<int>& tem = num1>num2?num1:num2;    
            vec.push_back(tem[0]);    
            tem.erase(tem.begin());    
        }    
        return vec;   
  
  
    }  
    vector<int> cmp(vector<int> & num1, vector<int> & num2)  
    {  
        int i = 0;  
        int j = 0;  
        while (i < num1.size() && j < num2.size())  
        {  
            if (num1[i]>num2[j])  
                return num1;  
            if (num1[i] < num2[j])  
                return num2;  
                  
            i++;  
            j++;  
        }  
        return num1;  
    }  
  
};  