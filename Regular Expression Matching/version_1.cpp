class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();  
        if (p[1] != '*')  
        {  
            if (s[0] != '\0' && (p[0] == s[0] || p[0] == '.')) return isMatch(s.substr(1), p.substr(1));  
            else return false;  
        }  
        else  
        {  
            // *s == *p
            int count=0;
            while (s[count] !='\0' && (s[count] == p[0] || p[0] == '.'))  
            {  
                if(isMatch(s.substr(count+1), p.substr(2))) return true;  
                count++;  
            }  
            return (isMatch(s, p.substr(2)));  
        }  
    }
};