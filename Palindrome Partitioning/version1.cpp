class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int len = s.size();
        if(len==0)
            return res;
            
        vector<string> temp;
        dfs(res, temp, s, 0);
        return res;
    }
    void dfs(vector<vector<string>> & res, vector<string> &temp, string &s, int start)
    {
        int len = s.size();
        if(start == len)
        {
            res.push_back(temp);
            return;
        }
        
        int pos = start+1;
        while(pos<= len)
        {
            string sub = s.substr(start, pos-start);
            if(is_Palin(sub))
            {
                temp.push_back(sub);
                dfs(res, temp, s, pos);
                temp.pop_back();
            }
            pos++;
        }
    }
    bool is_Palin(string &s)
    {
        int len =s.size();
        int left =0;
        int right = len-1;
        while(left<right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};