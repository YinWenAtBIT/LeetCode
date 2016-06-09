class Solution {
public:
    struct cmp_struct
    {
        bool operator()(pair<int, int> &l, pair<int, int> &r)
        {
            return l.first != r.first? l.first<r.first : r.second<l.second;  
        }
    }cmp;
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int len = envelopes.size();
        if(!len)
            return 0;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<pair<int, int>> dp;
        
        for(int i=0; i<len; i++)
        {
            int low =0, high = dp.size()-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(dp[mid].second<envelopes[i].second)
                    low = mid+1;
                else
                    high = mid-1;
            }
            if(low < dp.size())
                dp[low] = envelopes[i];
            else
                dp.push_back(envelopes[i]);
            
        }
        return dp.size();
    }
};