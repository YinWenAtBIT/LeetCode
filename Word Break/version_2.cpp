class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        if(!len)
            return false;
        vector<bool> dp(len+1, false);
        dp[0] = true;
        int min_len = 0;
        for(auto it = wordDict.begin(); it != wordDict.end(); it++)
        {
            if((*it).size()>min_len)
                min_len = (*it).size();
        }
        for(int i=1; i<=len; i++)
        {
            for(int l=1; l<=min_len; l++)
            {
                if(i-l<0)
                    break;
                
                if(dp[i-l])
                {
                    string temp = s.substr(i-l, l);
                    if(wordDict.count(temp))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
};