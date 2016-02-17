class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
            return false;
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        vector<vector<bool>> dp(len1+1);
        for(int i=0; i<len1+1; i++)
            dp[i].assign(len2+1, false);
        dp[0][0] = true;
        
        for(int i=1; i<len2+1; i++)
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        for(int i=1; i<len1+1; i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]; 
            
        for(int i=1; i<len1+1; i++)
            for(int j=1; j<len2+1; j++)
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1])  ||(dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                
        return dp[len1][len2];
    }
};