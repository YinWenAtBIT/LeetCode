class Solution {
public:
    int reverse(int x) {

        long res = 0;
        int max = 0x7FFFFFFF;
        int min = 0x80000000;
        while(x)
        {
            res = res*10 + x%10;
            x = x/10;
        }
        if (res > max || res < min) 
            return 0;

        return res;
    }
};