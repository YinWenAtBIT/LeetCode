class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m ==n | m==0)
            return m;

        int count=32;
        while((n&0x80000000) ==0)
        {
            m = m<<1;
            n = n<<1;
            count--;
        }
        int res=0;
        while((m&0x80000000) == (n&0x80000000))
        {
            if((m&0x80000000) == 0)
                res = res<<1;
            else
                res = (res<<1) |1;
            m = m<<1;
            n = n<<1;
            count--;
        }
        while(count)
        {
            res = res<<1;
            count--;
        }
        return res;
    }
};