class Solution {
public:
    int bulbSwitch(int n) {
        int count =0; 
        int zero_num = 0;
        while(n>0)
        {
            n = n - zero_num -1;
            zero_num +=2;
            count++;
        }
        if(n<0)
            count--;
        return count;
    }
};