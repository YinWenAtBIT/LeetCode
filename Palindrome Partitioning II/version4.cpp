class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len<2)
            return 0;
        vector<int> dp(len, 0);
        
        for(int i=1; i<len; i++)
        {
            int min_cut = 0x7fffffff;
            if(is_Palin(s, 0, i))
                dp[i] =0;
            else
            {
                for(int k=0; k<i; k++)
                {
                    int temp = dp[k] + i-k;
                    if(is_Palin(s, k+1, i))
                        temp = min(temp, dp[k]+1);
                    if(min_cut>temp)
                        min_cut = temp;
                }
                dp[i] = min_cut;
            }
        }
        return dp[len-1];
        
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