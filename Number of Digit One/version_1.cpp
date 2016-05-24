class Solution {
public:
    int countDigitOne(int n) {
        if(n<0)
            return 0;
        int res =0;
        for(int i=1; i<=n; i++)
        {
            int temp = i;
            while(temp)
            {
                int remain = temp%10;
                if(remain ==1)
                    res++;
                temp = temp/10;
            }
        }
        return res;
    }
};