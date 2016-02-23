class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len<2)
            return 0;
        vector<int> dp(len, 0);
        vector<vector<int>> flag(len);
        for(int i=0; i<len; i++)
            flag[i].assign(len, -1);
        
        for(int i=1; i<len; i++)
        {
            int min_cut = 0x7fffffff;
            if(is_Palin(s, flag, 0, i))
                dp[i] =0;
            else
            {
                for(int k=0; k<i; k++)
                {
                    int temp = dp[k] + i-k;
                    if(is_Palin(s, flag, k+1, i))
                        temp = min(temp, dp[k]+1);
                    if(min_cut>temp)
                        min_cut = temp;
                }
                dp[i] = min_cut;
            }
        }
        return dp[len-1];
        
    }
        

    
    
    bool is_Palin(string &s, vector<vector<int>> &flag, int i, int j)
    {
        if (i > j)
            return false;
        if (flag[i][j] != -1)
            return flag[i][j];
        if (i == j)
            return flag[i][j] = 1;
        if (s[i] != s[j])
            return flag[i][j] = 0;
        else {
            if (i + 1 == j)
                return flag[i][j] = 1;
            else
                return flag[i][j] = is_Palin(s, flag, i + 1, j - 1);
        }
    }
};