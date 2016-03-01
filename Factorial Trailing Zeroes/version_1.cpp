class Solution {
public:
    int trailingZeroes(int n) {
        int first = n/5;
        int res = first;
        while(first>4)
        {
            res += first/5;
            first /=5;
        }
        return res;
    }
};