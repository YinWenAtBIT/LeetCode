class Solution {
public:
    string convertToTitle(int n) {
        string res;
        if(n<0)
            return res;
        while(n)
        {
            int remain = n%26;
            if(remain ==0)
                res = 'Z'+res;
            else
                res = char('A'+remain-1)+res;
            remain? n = n/26: n=n/26-1;
        }
        return res;
    }
};