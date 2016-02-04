class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if(!len)
            return 0;
        int max_len =0;
        stack<char> save;
        stack<int> index;
        for(int i=0; i<len; i++)
        {
            if(s[i] == '(')
            {
                save.push(s[i]);
                index.push(i);
            }
            else
            {
                if(!save.empty() && save.top() == '(')
                {
                    save.pop();
                    index.pop();
                    if(save.empty())
                        max_len = i+1;
                    else
                        max_len = max(max_len, i-index.top());
                }
                else
                {
                    save.push(s[i]);
                    index.push(i);
                }
            }
        }
        return max_len;
    }
};