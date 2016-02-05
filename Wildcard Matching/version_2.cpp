class Solution {
public:
    bool isMatch(string s_str, string p_str) {
        const char * s= s_str.c_str();
        const char * p= p_str.c_str();
        
        const char* star=NULL;
        const char* ss=s; 
        while (*s) {
            if (*p == '*') {
                star = p++;
                ss = s;
                continue;
            }
            if (*p == '?' || *p == *s) {
                s++;
                p++;
                continue;
            }
            if (star) {
                p = star + 1; 
                s = ++ss;
                continue;      
            }
            return false;
        }
        while (*p == '*') {
            p++;
        }
        return !(*p);
    }
};