class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        if(!len)
            return true;
        unordered_set<char> used;
        unordered_map<char, char> dic;
        
        for(int i=0; i<len; i++)
        {
            if(dic.count(s[i]))
                s[i] = dic[s[i]];
            else
            {
                if(used.count(t[i]) ==0)
                {
                    used.insert(t[i]);
                    dic[s[i]] = t[i];
                    s[i] = t[i];
                }
            }
        }
        return s==t;
    }
};
