class Solution {
public:
    bool isUgly(int num) {

        if(num<=0)
            return false;
        if(num <=5)
            return true;
            
        int i= 2;
        while(num>5 && i<6)
        {

            if(num%i ==0)
            {
                num = num/i;
                i =1;
            }
            i++;
    
        }
        return i!=6;

    }
};