class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int pos1 =0;
        int pos2 =0;
        int num1, num2;
        
        
        while(pos1<len1 && pos2 <len2)
        {
            pos1 = jump_zero(version1, pos1);
            pos2 = jump_zero(version2, pos2);
            if(pos1 == len1 || pos2 == len2)
                break;
            else
            {
                int nextdot1 = version1.find('.', pos1);
                int nextdot2 = version2.find('.', pos2);
                if(nextdot1 == string::npos)
                {
                    nextdot1=len1-1;
                    num1 = atoi(version1.substr(pos1).c_str());
                }
                else
                    num1 = atoi(version1.substr(pos1, nextdot1-pos1).c_str());
                if(nextdot2 == string::npos)
                {
                    nextdot2 = len2-1;
                    num2 = atoi(version2.substr(pos2).c_str());
                }
                else
                    num2 = atoi(version2.substr(pos2, nextdot2-pos2).c_str());
                    
                if(num1>num2)
                    return 1;
                else if(num2>num1)
                    return -1;
                else
                {
                    pos1 = nextdot1+1;
                    pos2 = nextdot2+1;
                }
            }
        }
        
        if(pos1 == len1 && pos2 ==len2)
            return 0;
        if(pos1 == len1 || pos2 == len2)
        {
            if(pos1 == len1)
            {
                while(pos2<len2)
                {
                    if(version2[pos2] == '.' || version2[pos2] == '0')
                        pos2++;
                    else
                        return -1;
                }
                return 0;
            }
            else
            {
                while(pos1<len1)
                {
                    if(version1[pos1] == '.' || version1[pos1] == '0')
                        pos1++;
                    else
                        return 1;
                }
                return 0;                    
            }
        }
    }
    
    int jump_zero(string & s, int start)
    {
        int len = s.size();
        if(start >=len)
            return start;
        while(start<len)
        {
            if(s[start] =='0')
                start++;
            else
                break;
        }
        return start;
    }
    
};
