class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        int len = s.size();
        stack<char> mystack;
        for(int i =0; i<len; i++)
        {
            if(s[i] == '(' || s[i] == '['|| s[i] == '{')
                mystack.push(s[i]);
            else
            {
                if(s[i] == ')')
                {
                    if(!mystack.empty() && mystack.top() == '(')
                        mystack.pop();
                    else
                        return false;
                }
                 if(s[i] == ']')
                {
                    if( !mystack.empty() && mystack.top() == '[')
                        mystack.pop();
                    else
                        return false;
                }
                if(s[i] == '}')
                {
                    if(!mystack.empty() && mystack.top() =='{')
                        mystack.pop();
                    else
                        return false;
                }                
            }
            
        }
        if(mystack.empty())
            return true;
        return false;
    }
};