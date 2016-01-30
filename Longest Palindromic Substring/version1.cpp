class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if(length ==1 | length ==2)
            return s;
        
            
        int odd_max_mid =-1;
        int odd_max_len = 0;
        int even_max_mid = -1;
        int even_max_len = 0;
        int count_odd=0;
        int count_even=0;
        
        
        const char * start = s.c_str();
        
        
        int odd_mid_index[1000] = {0};
        int even_mid_index[1000] = {0};
        
        int i=0;
        for(; i<length -2; i++)
        {
            if(s[i] == s[i+2])
            {
                odd_mid_index[count_odd] = i+1;
                ++count_odd;
            }
            
            if(s[i] == s[i+1])
            {
                even_mid_index[count_even] = i;
                ++count_even;
            }
        }
        
        if(s[i] == s[i+1])
        {
            even_mid_index[count_even] = i;
            ++count_even;
        }
        
        
        int temp_len;
        for(i=0; i<count_odd; i++)
        {
            temp_len = check_Palindromic_len(s, odd_mid_index[i], 1);
            if(temp_len >odd_max_len)
            {
                odd_max_len = temp_len;
                odd_max_mid = odd_mid_index[i];
            }
        }
        
        for(int i=0; i<count_even; i++)
        {
            temp_len = check_Palindromic_len(s, even_mid_index[i], 0);
            if(temp_len >even_max_len)
            {
                even_max_len = temp_len;
                even_max_mid = even_mid_index[i];
            }
        }
        if(even_max_len*2 >  2*odd_max_len +1)
            return string(s, even_max_mid-even_max_len +1, 2*even_max_len);
        else
            return string(s, odd_max_mid-odd_max_len, 2*odd_max_len+1);
        
    }
    int check_Palindromic_len(string &s, int middle, bool odd)
    {
        int len = s.size();
        int max_len =1;
        if(odd)
        {
            while(middle - max_len >=0 && middle +max_len <len)
            {
                if(s[middle - max_len] == s[middle +max_len])
                    ++max_len;
                else
                    break;
                
            }
            return max_len-1;
        }
        else
        {
            while(middle - max_len >=0 && middle +max_len+1 <len)
            {
                if(s[middle - max_len] == s[middle +max_len+1])
                    ++max_len;
                else
                    break;
                
            }
            return max_len;            
        }
    }
};