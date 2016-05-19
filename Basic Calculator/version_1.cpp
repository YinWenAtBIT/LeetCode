class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        if(!len)
            return 0;
        
        stack<int> st;
        int res = 0;
        int sign = 1;
        for(int i=0; i<len; i++)
        {
            if(isnum(s[i]))
            {
                int cur = s[i] -'0';
                while(i+1<len && isnum(s[i+1]))
                {
                    cur = cur*10+s[++i] -'0';
                }
                res +=sign*cur;
            }
            else
            {
                if(s[i] == '-')
                    sign = -1;
                else if(s[i] == '+')
                    sign = 1;
                else if(s[i] == '(')
                {
                    st.push(res);
                    st.push(sign);
                    res = 0;
                    sign =1;
                }
                else if(s[i] == ')')
                {
                    int temp = st.top();
                    st.pop();
                    res = st.top() +temp*res;
                    st.pop();
                    sign = 1;
                }
            }
        }
        return res;
    }
    
    bool isnum(char c)
    {
        if(c>='0' && c<='9')
            return true;
        return false;
    }
};