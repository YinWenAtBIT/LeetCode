class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(is_Palin(s, 0, len-1))
            return 0;
        vector<vector<int>> dp(len);
        for(int i=0; i<len; i++)
            dp[i].assign(len, 0);
        
        for(int l=1; l<len; l++)
            for(int j=0; j+l<len; j++)
            {
                if(is_Palin(s, j, j+l))
                    dp[j][j+l] = 0;
                else
                {
                    int min =0x7fffffff;
                    for(int k=0; k<l; k++)
                    {
                        int temp = dp[j][j+k] + dp[j+k+1][j+l];
                        if(min>temp)
                            min = temp;
                    }
                    dp[j][j+l] = min+1;
                }
            }
        return dp[0][len-1];
        
    }
    
    bool is_Palin(string &s, int start, int end)
    {
        int left =start;
        int right = end;
        while(left<right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};