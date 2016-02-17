class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()<4)
            return res;
        string temp;
        dfs(res, s, temp, 0, 0);
        return res;
    }
    void dfs(vector<string> &res, string &s, string &temp, int num, int start)
    {
        if(num ==4 && start == s.size())
            res.push_back(temp);
        if(num == 4 || start == s.size())
            return;
        
        int len = s.size();
        if(num !=0)
            temp.push_back('.');
        temp.push_back(s[start]);
        dfs(res, s, temp, num+1, start+1);
        temp.pop_back();
        if(num !=0)
            temp.pop_back();
        
        if(start+1<len && s[start] != '0')
        {
            if(num !=0)
                temp.push_back('.');
            temp.push_back(s[start]);
            temp.push_back(s[start+1]);
            dfs(res, s, temp, num+1, start+2);
            temp.pop_back();
            temp.pop_back();
            if(num !=0)
                temp.pop_back();
        }
        
        bool flag = false;
        if(start+2<len)
        {
            if(s[start] == '1')
                flag = true;
            if(s[start] == '2')
            {
                if(s[start+1]<='4')
                    flag = true;
                else if(s[start+1] == '5' && s[start+2]<='5')
                    flag = true;
            }
            if(flag)
            {
                if(num !=0)
                    temp.push_back('.');
                temp.push_back(s[start]);
                temp.push_back(s[start+1]);
                temp.push_back(s[start+2]);
                dfs(res, s, temp, num+1, start+3);
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
                if(num !=0)
                    temp.pop_back();
            }
            
        }
    }
};