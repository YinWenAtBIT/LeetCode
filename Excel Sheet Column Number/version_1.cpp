class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        if(!len)
            return 0;
        int pos =0;
        long long res =0;
        while(len)
        {
            res *=26;
            if(res > INT_MAX)
                return INT_MAX;
                
            if(s[pos] == 'Z')
                res +=26;
            else
                res +=s[pos]-'A'+1;
            len --;
            pos++;
        }
        return int(res);
    }
};