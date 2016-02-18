class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty())
            return 1;
        int num =0;
        string temp;
        numD(s, t, temp, 0, num);
        return num;
        
    }
    void numD(string &s, string &t, string &temp, int start, int &count)
    {
        int len_t = t.size();
        if(temp.size() == len_t)
        {
            if(temp == t)
            {
                count++;
                return;
            }
            else
                return;
        }
        int len_s = s.size();
        if(temp.size() +len_s - start < len_t)
            return;
        
        numD(s, t, temp, start+1, count);
        temp.push_back(s[start]);
        numD(s, t, temp, start+1, count);
        temp.pop_back();
        
    }
};