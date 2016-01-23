class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        
        size_t length = s.size();
        size_t max=1;
        size_t laststop =0;
        size_t lastlength;
        
        bool flag[128] ={false};
        size_t lastApper[128];
        
        for(size_t i=0; i< length; i++)
        {
            if(!flag[s[i]])
            {
                flag[s[i]] = true;
                lastApper[s[i]] = i;
            }
            else
            {
                if(lastApper[s[i]] < laststop)
                    lastApper[s[i]] = i;
                else
                {
                    lastlength = i - laststop;
                    if(lastlength > max)
                        max = lastlength;
                    
                    laststop = lastApper[s[i]]+1;
                    lastApper[s[i]] = i;
                }

            }
        }
        lastlength = length - laststop;
        if(lastlength > max)
            max = lastlength;
        return max;
    }
};