class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_s = haystack.size();
        int len_p = needle.size();
        if(!len_s && !len_p)
            return 0;
        if(!len_s)
            return -1;
        if(!len_p)
            return 0;
        
        for(int i=0; i<len_s- len_p +1; i++)
        {
            int j=0;
            for(; j<len_p; j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == len_p)
                return i;
        }
        return -1;
    }
};