class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if(len<2)
            return true;
        int left=0, right = len-1;
        bool flag = false;
        while(left<right)
        {
            flag = false;
            while(!((s[left]>='0' && s[left]<='9') || (s[left]>='a' && s[left]<='z') || (s[left]>='A' && s[left]<='Z')))
                left++;
            while(!((s[right]>='0' && s[right]<='9') || (s[right]>='a' && s[right]<='z') || (s[right]>='A' && s[right]<='Z')))
                right--;
            if(left>= right)
                break;
            if(s[left]>='0' && s[left]<='9')
            {
                if(s[left] == s[right])
                    flag = true;
            }
            else
            {
                int a, b;
                if(s[left]>='a' && s[left]<='z')
                    a= s[left]-'a';
                else
                    a = s[left]-'A';
                    
                if(s[right]>='a' && s[right]<='z')
                    b= s[right]-'a';
                else
                    b = s[right]-'A';
                if(a==b)
                    flag = true;
            }
            if(flag)
            {
                left++;
                right--;
            }
            else
                return false;

        }
        return true;
    }
};