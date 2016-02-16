class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if(!len )
            return 0;
        if(s[0] =='0')
            return 0;
        int last = 1;
        int last_before = 1;
        int now;
        for(int i=1; i<len ;i++)
        {
            if((s[i]<='6' && s[i-1] == '2' )|| s[i-1] == '1')
                if(s[i] != '0')
                    now = last+last_before;
                else
                    now = last_before;
            else if(s[i] == '0')
                return 0;
            else
                now = last;
                
            last_before = last;
            last = now;                
            
        }
        return last;
    }
};