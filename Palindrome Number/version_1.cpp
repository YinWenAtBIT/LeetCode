class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0)
            return false;
        int max =x;
        int min =0;
        while(max)
        {
            min = min*10 +max%10;
            max /=10;
        }
        if(min == x)
            return true;
        return false;
        
    }
};