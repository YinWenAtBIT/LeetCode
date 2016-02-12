class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        if(!len)
            return 0;
        
        int i= len-1;
        while(!((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')) & i>=0)
            i--;
        int count =0;
        while(((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z')) & i>=0)
        {
            i--;
            count++;
        }
        return count;
    }
};