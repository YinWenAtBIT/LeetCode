class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.size();
        if(len <2)
            return s;
        if(is_Palin(s))
            return s;
        int half = len/2;
        if(!(len%2))
            half--;
        
        while(half)
        {
            if(mid_part_Palin(half, s))
            {
                int sub_start = 2*half+1;
                
                string add = s.substr(sub_start);
                reverse(add.begin(), add.end());
                string res = add +s;
                return res;
            }
            if(nomid_part_Palin(half, s))
            {
                int sub_start = 2*half;
                
                string add = s.substr(sub_start);
                reverse(add.begin(), add.end());
                string res = add +s;
                return res;                
            }
            
            half--;
        }
        string add = s.substr(1);
        reverse(add.begin(), add.end());
        string res = add +s;
        return res;
    }
    
    bool is_Palin(string &s)
    {
        int len = s.size();
        int i=0, j=len-1;
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool mid_part_Palin(int mid, string &s)
    {
        int len = s.size();
        int left= mid-1, right = mid+1;
        while(left>=0)
        {
            if(s[left] != s[right])
                return false;
            left--;
            right++;
        }
        return true;
    }
    bool nomid_part_Palin(int mid, string &s)
    {
        int left =mid-1;
        int right = mid;
        while(left>=0)
        {
            if(s[left] != s[right])
                return false;
            left--;
            right++;
            
        }
        return true;
    }
};