class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int len = strs.size();
        if(len ==0)
            return res;
        char temp;
        int j=0;
        for(int i=0; i<strs[0].size();i++)
        {
            temp =strs[0][i];
            for(j=0; j<len; j++)
            {
                if(temp != strs[j][i])
                    break;
            }
            if(j != len)
                break;
            
            res +=temp;
        }
        return res;
    }
};