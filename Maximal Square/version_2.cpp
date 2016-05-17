class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int M = matrix.size(), N = matrix[0].size(), res = 0;
        vector<vector<int>> dp(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++i) if (matrix[i][0] == '1') {
            dp[i][0] = 1; res = 1;
        }
        for (int j = 0; j < N; ++j) if (matrix[0][j] == '1') {
            dp[0][j] = 1; res = 1;
        }
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                if (matrix[i][j] == '1') 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};