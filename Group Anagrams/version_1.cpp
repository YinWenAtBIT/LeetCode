class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> res;
        if(!len)
            return res;
        
        unordered_map<string, vector<string>> group;
        for(int i=0; i<len; i++)
        {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            group[temp].push_back(strs[i]);
        }
        for(auto it = group.begin(); it != group.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }
};