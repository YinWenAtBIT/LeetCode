class Solution {
public:
    int myAtoi(string str) {
        int len= str.size();
        int flag =1;
        int max= 0x7fffffff;
        int min= 0x80000000;
        int flagcount =0;
        int startnum_fiag =1;

        long res =0;
        for(int i=0; i<len; i++)
        {
            if(str[i]>='0' && str[i]<= '9')
            {
                res = res*10 + str[i] -'0';
                startnum_fiag  =0;
                
                if(res > max)
                    if(flag ==1)
                        return max;
                    else
                        return min;
            }
            else
            {
                if(str[i] == '+' || str[i] == '-')
                {
                    if(str[i] == '+')
                        flag = 1;
                    else
                        flag = -1; 
                        
                    startnum_fiag =0;
                    
                    if(flagcount == 0) 
                        flagcount =1;
                    else 
                        return 0;
                }
                else if(str[i] == ' ' && startnum_fiag)
                    continue;
                else
                    break;
            }
        }


        return res*flag;
      
    }
};