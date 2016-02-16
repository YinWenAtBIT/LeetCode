class Solution {
public:
    bool isScramble(string s1, string s2) {
        return is_part(s1, s2);
    }
    
    bool is_part(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
        if(s1.size()  <2)
            return s1 == s2;
        if(s1.size() ==2)
        {
            if(s1[0] ==s2[0] && s1[1] == s2[1])
                return true;
            if(s1[1] ==s2[0] && s1[0] == s2[1])
                return true;
            return false;
        }
        
        //string temp1 = s1, temp2 = s2;
        //sort(temp1.begin(), temp1.end());
        //sort(temp2.begin(), temp2.end());
        //if(temp1 != temp2)
        //    return false;
        
        unordered_map<char, int> cur;
        unordered_map<char, int> from_head;
        unordered_map<char, int> from_end;
        
        int len = s1.size();
        for(int i=0; i<len -1; i++)
        {
            cur[s1[i]]++;
            from_head[s2[i]]++;
            from_end[s2[len-1-i]]++;
            if(cur == from_head)
            {
                if(is_part(s1.substr(0, i+1), s2.substr(0, i+1)))
                {
                    if( is_part(s1.substr(i+1), s2.substr(i+1)))
                        return true;
                }
            }
            if(cur == from_end)
            {
                if(is_part(s1.substr(0, i+1), s2.substr(len-1-i)))
                {
                    return is_part(s1.substr(i+1), s2.substr(0, len-(i+1)));
                }
                return false;                
            }
        }
        return false;
    }
};