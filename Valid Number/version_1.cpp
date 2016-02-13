class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        if(!len)
            return false;
        
        bool start= false;
        bool e_start = false;
        bool dot = false;
        bool num_before_dot = false;
        bool num_after_dot = false;
        bool exp_flag =false;
        bool middle_blank =false;
        bool num_in_dot_exp = false;
        bool num_exist = false;
        bool num_after_exp = false;
        bool pos_minus_flag_before_exp = false;
        bool pos_minus_flag_after_exp = false;
        for(int i=0; i<len; i++)
        {
            if(s[i]==' ')
            {
                if(!start)
                    continue;
                else
                    middle_blank = true;
            }
            else if(middle_blank)
                return false;
            else if(s[i] == '.')
            {
                if(!dot && !exp_flag)
                {
                    dot = true;
                    start = true;
                }
                else
                    return false;
            }
            else if(s[i] == 'e')
            {
                if(!num_exist || exp_flag || (dot & !num_before_dot &  !num_after_dot))
                    return false;
                else
                    exp_flag =true;
            }
            else if(s[i] == '+' || s[i] == '-')
            {
                if(!start)
                {
                    pos_minus_flag_before_exp = true;
                    start = true;
                }
                else if(exp_flag)
                {
                    if(!pos_minus_flag_after_exp & !e_start)
                    {
                        e_start = true;
                        pos_minus_flag_after_exp = true;
                    }
                    else
                        return false;
                }
                else
                    return false;
                
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                start = true;
                num_exist = true;
                if(dot)
                    num_after_dot = true;
                else
                    num_before_dot = true;
                    
                if(exp_flag)
                {
                    e_start = true;
                    num_after_exp = true;
                }
                    
            }
            else
                return false;
    
        }
        if(exp_flag)
            return num_after_exp;
        if(dot)
            return (num_before_dot || num_after_dot);
        else
            return num_exist;
    }
};