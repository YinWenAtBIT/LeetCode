class Solution {
public:
    vector<bool> dp;
    vector<string> res;
    vector<unordered_set<int>> next_loc;
    vector<string> temp;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        if(!len)
            return res;
        int min_len=0x7ffffff;
        int max_len =0;
        for(auto it = wordDict.begin(); it != wordDict.end(); it++)
        {
            int temp_len = (*it).size();
            if(temp_len>max_len)
                max_len = temp_len;
            if(temp_len<min_len)
                min_len = temp_len;
        }
        dp.assign(len+1, false);
        next_loc.resize(len+1);
        dp[0] = true;
        for(int i=1; i<=len; i++)
            for(int l=min_len; l<=max_len; l++)
            {
                if(i-l <0)
                    break;
                if(dp[i-l])
                {
                    string sub = s.substr(i-l, l);
                    if(wordDict.count(sub))
                    {
                        dp[i] = true;
                        next_loc[i-l].insert(i);
                    }
                }
            }
        if(!dp[len])
            return res;
        dfs(s, 0);
        return res;
    }
    void dfs(string &s, int start)
    {
        int len = s.size();
        if(start == len)
        {
            string output;
            for(int i=0; i<temp.size() -1; i++)
            {
                output +=temp[i];
                output += ' ';
            }
            output += temp[temp.size()-1];
            res.push_back(output);
            return;
        }
        
        unordered_set<int> & next = next_loc[start];
        for(auto it = next.begin(); it != next.end(); it++)
        {
            temp.push_back(s.substr(start, *it -start));
            dfs(s, *it);
            temp.pop_back();
        }
    }
};