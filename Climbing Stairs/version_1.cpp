class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int next_to_last = 1;
        int temp;
        while(n> 1)
        {
            temp = last;
            last = last+next_to_last;
            next_to_last = temp;
            n--;
        }
        return last;
    }
};