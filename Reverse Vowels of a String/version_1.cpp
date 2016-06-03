class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        if(!len)
            return s;
        
        int left= 0, right = len-1;
        while(left<right)
        {
            while(!is_vowel(s[left]))
                left++;
            while(!is_vowel(s[right]))
                right--;
            if(left<right)
                swap(s[left++], s[right--]);
        }
        return s;
    }
    bool is_vowel(char c)
    {
        switch(c)
        {
            case 'i':
            case 'o':
            case 'u':
            case 'e':
            case 'a':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':return true;
            default:return false;
        }
    }
    
};