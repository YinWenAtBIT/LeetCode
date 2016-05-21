class Solution {
public:
    int calculate(string s) {
        char first, second;
        bool begin = false;
        s+='+';
        int len = s.size();
        if(len<2)
            return 0;
        
        int res =0;
        int i=0;
        int sign = 1;
        int before = get_num(s, i);
        
        for(; i<len; )
        {
            if(s[i] == '+' || s[i] == '-')
            {
                res += sign*before;
                sign = s[i] == '+'?1:-1;
                i++;
            }
            else if(s[i] =='*' )
            {
                i++;
                int temp = get_num(s, i);
                before = before *temp;
            }
            else if(s[i] == '/')
            {
                i++;
                int temp = get_num(s, i);
                before = before /temp;
            }
            else if(isnum(s[i]))
            {
                before = get_num(s, i);
            }
            else
                i++;
        }
        return res;
    }
    
    bool isnum(char c)
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
    
    int get_num(string &s, int &i)
    {
        int len = s.size();
        int cur = 0;
        while(i<len && (isnum(s[i]) || s[i] == ' '))
        {
            if(isnum(s[i]))
                cur = 10*cur + s[i]-'0';
 
            i++;
        }
        return cur;     
    }
    
};