class Solution {
public:
    struct cmp_struct
    {
        bool operator()(pair<int, int> &l, pair<int, int> &r)
        {
            return l.first != r.first? l.first<r.first : l.second<r.second;  
        }
    }cmp;
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if(!len)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(len, 1);
        
        for(int i=1; i<len; i++)
        {
            for(int j=i-1; j>=0 && j>=dp[i]-1; j--)
            {
                if(envelopes[i].first >envelopes[j].first && envelopes[i].second >envelopes[j].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        int max_ans =0;
        for(int i=0; i<len; i++)
            max_ans = max(max_ans, dp[i]);
        return max_ans;
    }
};