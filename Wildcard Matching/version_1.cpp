class Solution {
public:
    bool isMatch(string s, string p) {
        Match(s,p, 0, 0);
    }
    
    bool Match(string &s, string &p, int s_index, int p_index)
    {
        if(p_index == p.size())
            return s_index == s.size();
        
        if(p[p_index] != '*')
        {
            if(p[p_index] == s[s_index] || p[p_index] == '?')
                return Match(s, p, s_index+1, p_index+1);
            else
                return false;
        }
        else
        {
            int shift =1;
            while(s_index+shift<s.size())
            {
                if(Match(s, p, s_index+shift, p_index+1))
                    return true;
                shift++;
            }
            return Match(s,p, s_index, p_index+1);
        }
    }
};