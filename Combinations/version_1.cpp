class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(!n || !k)
            return res;
         
        vector<bool> num(n, false);
        vector<int> temp;
        dfs(res, num, temp, 0, 0, k);
        return res;
        
    }
    void dfs(vector<vector<int>> &res, vector<bool> &num, vector<int> &temp, int now, int start, int k)
    {
        if(now == k)
        {
            res.push_back(temp);
            return;
        }
        
        int len = num.size();
        for(int i=start; i<len; i++)
        {
            if(!num[i])
            {
                num[i] =true;
                temp.push_back(i+1);
                dfs(res, num, temp, now+1, i+1, k);
                num[i] = false;
                temp.pop_back();
            }
        }
    }
};