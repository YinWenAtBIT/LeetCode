class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if(!len)
            return 0;
        stack<int> st;
        for(int i=0; i<len; i++)
        {
            string &now = tokens[i];
            if(now =="+" || now =="-" || now =="*" || now =="/")
            {
                int ope2 = st.top();
                st.pop();
                int ope1 = st.top();
                st.pop();
                int out;
                if(now == "+")
                    out = ope1 + ope2;
                if(now == "-")
                    out = ope1 - ope2;
                if(now == "*")
                    out = ope1 * ope2;
                if(now == "/")
                    out = ope1 / ope2;
                st.push(out);
            }
            else
            {
                int new_op = atoi(now.c_str());
                st.push(new_op);
            }
        }
        return st.top();
    }
};