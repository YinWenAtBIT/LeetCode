class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> num(n, false);
        set_Permutation(num, res, 0, n, k);
        return res;
    }
    
    void set_Permutation(vector<bool> & num, string & res, int now, int n, int k)
    {
        if(now == n)
            return;
            
        int skip_num=1;
        for(int i=2; i< n-now; i++)
            skip_num *=i;
        int skip=0;
        for(int i=1; i<n-now; i++)
        {
            if(i*skip_num < k)
                skip = i;
            else
                break;
        }
        
        int count =0;
        int pos =0;
        while(count<=skip)
        {
            if(num[pos])
            {
                ++pos;
                continue;
            }
            ++count;
            ++pos;
        }
        
        res.push_back(pos+'0');
        num[pos-1] = true;
        set_Permutation(num, res, now+1, n, k-skip*skip_num);
    }
};