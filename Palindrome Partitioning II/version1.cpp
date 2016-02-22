class Solution {
public:
    int minCut(string s) {
        int count = 0;
        int len = s.size();
        
        int last_stop=0;    
        int end = len -1;
        while(!is_Palin(s, last_stop, end))
        {
            int i;
            for(i= end-1; i>last_stop; i--)
            {
                bool flag1 = false;
                bool flag2 = false;
                int last_stop_temp;
                int end_temp;
                if(is_Palin(s, last_stop, i))
                {
                    if(is_Palin(s, i+1, end))
                        return count+1;
                    last_stop_temp = i+1;
                    flag1 = true;
                }
                
                int sub_len = end - i;
                if(is_Palin(s, last_stop+sub_len, end))
                {
                    if(is_Palin(s, last_stop, last_stop+sub_len -1))
                        return count+1;
                    end_temp = last_stop +sub_len-1;
                    flag2 = true;
                }
                
                if(is_Palin(s, last_stop, last_stop+sub_len-1) && is_Palin(s, last_stop+sub_len, i) && is_Palin(s, i+1, end))
                    return count+2;
                    
                if(flag1)
                {
                    count++;
                    last_stop = last_stop_temp;
                    break;
                }
                if(flag2)
                {
                    count++;
                    end = end_temp;
                    break;
                }
                    
            }
            if(i == last_stop)
            {
                count++;
                last_stop++;
            }
        }
        return count;
    }
    
    
    bool is_Palin(string &s, int start, int end)
    {
        int left =start;
        int right = end;
        while(left<right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};