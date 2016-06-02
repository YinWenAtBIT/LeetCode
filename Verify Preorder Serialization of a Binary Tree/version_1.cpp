class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
        if(!len)
            return false;
        
        stack<bool> st;
        int start =0;
        while(start <len)
        {
            if(get_num(preorder, start))
                st.push(true);
            else
            {
                if(!st.empty())
                    st.pop();
                else if(start == len)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
    bool get_num(string &preorder, int &start)
    {
        int len = preorder.size();
        while(preorder[start] == ',')
            start ++;
        if(preorder[start] == '#')
        {
            start ++;
            return false;
        }
        while(preorder[start] !=',')
            start++;
        return true;
    }
};