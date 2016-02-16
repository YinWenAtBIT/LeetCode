class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int H = matrix.size(), W = matrix[0].size();
        int height[W+1];
        int i, j , MAX = 0, leftarea = 0, rightarea = 0;
        stack<int> st;
        for(i = 0; i <= W; height[i] = 0, ++i);
        for(i = 0; i < H; ++i){
            while(!st.empty()) st.pop();
            for(j = 0; j < W; ++j){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int j = 0; j <= W; ++j){
                while(!st.empty() && height[st.top()] > height[j]){
                    int tmp = st.top();
                    st.pop();
                    leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp];
                    rightarea = (j - tmp - 1) * height[tmp];
                    if((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
                }
                st.push(j);
            }
        }
        return MAX;
    }
};