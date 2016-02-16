class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(!len)
            return 0;
        heights.push_back(0);
        int square =0;
        stack<int> st;
        for(int i=0; i<len+1; i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int temp = st.top();
                st.pop();
                int left = (st.empty()?temp+1:temp-st.top())*heights[temp];
                int right = (i-temp-1)*heights[temp];
                if(square<left+right)
                    square = left+right;
            }
            st.push(i);
        }
        return square;
    }
};