class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0) {
            return 0;
        }
        bool flag = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            flag = false;
        }
        const int MAX_INT = 0x7fffffff;
        long long diva = dividend;
        long long divb = divisor;
        if (diva < 0) {
            diva = 0 - diva;
        }
        if (divb < 0) {
            divb = 0 - divb;
        }
        long long tmp, count;
        long ret = 0;
        while (diva >= divb) {
            tmp = divb;
            count = 1;
            while (tmp + tmp <= diva) {
                tmp += tmp;
                count += count;
            }
            ret += count;
            diva -= tmp;
        }
        if(flag)
            if(ret>= MAX_INT)
                return MAX_INT;
            else
                return (int) ret;
        else
            return int(0-ret);
    }
};