class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0)
            return res;
        int left_bracket=n, right_bracket =n;
        string tmp;
        dfs(res, tmp, left_bracket, right_bracket);
        
        return res;
        
    }
    void dfs(vector<string> &res, string & tmp, int left_bracket, int right_bracket)
    {
        if(!left_bracket && !right_bracket)
            if(isValid(tmp))
            {
                res.push_back(tmp);
                return;
            }
        
        if(left_bracket)
        {
            tmp.push_back('(');
            dfs(res, tmp, left_bracket-1, right_bracket);
            tmp.pop_back();
        }
        
        if(right_bracket)
        {
            tmp.push_back(')');
            dfs(res, tmp, left_bracket, right_bracket-1);
            tmp.pop_back();
        }
    }
    
    
    
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