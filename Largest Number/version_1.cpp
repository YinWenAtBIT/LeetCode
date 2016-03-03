class Solution {
public:
    struct cmp
    {
        bool operator ()(string a, string b)
        {
            string a_first = a+b;
            string b_first = b+a;
            int len = a_first.size();
            for(int i=0; i<len; i++)
            {
                if(a_first[i]> b_first[i])
                    return true;
                else if(a_first[i]< b_first[i])
                    return false;
                else
                    continue;
            }
            return false;
        }
    } cmp;
    
    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        string res;
        if(!len)
            return res;
        
        vector<string> num;
        for(int i=0; i<len; i++)
            num.push_back(itoa(nums[i]));
            
        sort(num.begin(), num.end(), cmp);
        for(int i=0; i<len; i++)
            res+=num[i];
            
        while(res.size() !=1 && res[0] == '0')
        {
            res.assign(res.begin()+1, res.end());
        }
        
        return res;
    }
    string itoa(int i)
    {
        string res;
        if(i ==0)
        {
            res.push_back('0');
            return res;
        }
        while(i)
        {
            int temp = i%10;
            i = i/10;
            res = static_cast<char>(temp +'0')+res;
        }
        return res;
    }
};