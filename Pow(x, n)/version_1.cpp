class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1)
            return 1;
        if(x == -1)
            return n%2 == 0? 1:-1;
            
        double res =1;
        
        bool flag =true;
        bool cont = true;
        if(n<0)
        {
            flag =false;
            n = 0-n;
        }
        while(n>0 && cont)
        {
            int exp_num =1;
            int sum=0;
            double next = x;
            while(sum+exp_num<=n)
            {
                res *= next;
                if(res == 0 || res== 1.7976931348623158e+308 || res == 2.2250738585072014e-308)
                {
                    cont = false;
                    break;
                }
                sum +=exp_num;
                next *= next;
                exp_num +=exp_num;
            }
            n -= sum;
        }
        
        if(!flag)
        {
            if(res)
                res = 1.0/res;
            else
                res = x>0? 1.7976931348623158e+308: 2.2250738585072014e-308;
        }
        return res;
    }
};