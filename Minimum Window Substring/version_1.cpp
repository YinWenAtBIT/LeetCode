class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int len_s = s.size();
        int len_t = t.size();
        if(!len_s || !len_t || len_s<len_t)
            return res;
        
        map<char, int> chs;
        for(int i=0; i<len_t; i++)
            chs[t[i]]++;
        
        int total = chs.size();
        map<char, int> cur;
        
        int left=0;
        int count =0;
        bool appear = false;
        int start_pos=0;
        int min = len_s+1;
        for(int i=0; i<len_s; i++)
        {
            if(t.find(s[i]) == string::npos)
            {
                if(!appear)
                    left++;
                else
                    continue;
            }
            else
            {
                ++cur[s[i]];
                appear =true;
                if(cur[s[i]] == chs[s[i]])
                {
                    count++;
                    if(count == total &&(i-left+1<min))
                    {
                        min = i-left+1;
                        start_pos = left;

                    }
                }
                else if(cur[s[i]] >chs[s[i]] && s[left] == s[i])
                {
                    while(chs[s[left]] < cur[s[left]])
                    {
                        cur[s[left]]--;
                        left++;
                        while(t.find(s[left]) == string::npos)
                            left++;
                    }
                    
                    if(count == total && (i-left+1<min))
                    {
                        min = i-left+1;
                        start_pos = left;
                    }
                }

            }
        }
        if(min <len_s+1)
            return s.substr(start_pos, min);
        return res;
    }
};