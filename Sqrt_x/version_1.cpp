class Solution {
public:
    int mySqrt(int x) {
        if(x<0)
            return 0x80000000;
            
        int res =0;
        int add =1;
        int now, last =0;
        while(1)
        {
            add =1;
            while(1)
            {
                now =(res+add)*(res+add);
                if(now<last || now >x)
                    break;
                last = now;
                res +=add;
                add += add;
            }
            if(add ==1)
                break;
        }
        return res;
    }
};