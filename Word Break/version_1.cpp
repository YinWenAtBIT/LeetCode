class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        if(!len)
            return false;
        if(wordDict.count(s))
            return true;
        return dfs(s, wordDict, 0);
        
    }
    bool dfs(string &s, unordered_set<string>& wordDict, int start)
    {
        int len = s.size();
        if(start == len)
            return true;
        
        int remain = len -start;
        for(int l=1; l<=remain; l++)
        {
            string temp = s.substr(start, l);
            if(wordDict.count(temp))
                if(dfs(s, wordDict, start+l))
                    return true;
        }
        return false;
    }
};