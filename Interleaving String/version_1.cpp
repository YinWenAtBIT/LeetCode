class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size())
            return false;
        return isInter(s1, s2, s3, 0, 0);
    }
    bool isInter(string &s1, string &s2, string &s3, int pos1, int pos2)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        int pos3 = pos1+pos2;
        
        if(pos3 == len3)
            return true;
        
        if(pos1< len1 && s1[pos1] ==s3[pos3])
        {
            if(isInter(s1, s2, s3, pos1+1, pos2))
                return true;
        }
        if(pos2< len2 && s2[pos2] ==s3[pos3])
        {
            if(isInter(s1, s2, s3, pos1, pos2+1))
                return true;
        }
        return false;
    }
};