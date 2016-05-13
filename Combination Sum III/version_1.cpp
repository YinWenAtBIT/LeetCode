class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum =0;
        vector<vector<int>> res;
        vector<int> temp;
        for(int i=1; i<10; i++)
        {
            temp.push_back(i);
            sum+=i;
            dfs(res, temp, i, sum, k, n);
            sum-=i;
            temp.pop_back();
        }
        return res;
    }
    
    bool dfs(vector<vector<int>> & res, vector<int> &temp, int now, int sum, int k, int n)
    {
        int now_len = temp.size();
        if(now_len == k )
        {
            if(sum ==n)
            {
                res.push_back(temp);
                return true;
            }
            else
                return false;
        }
        
        if(sum>= n)
            return false;
        
        int remain = n -sum;
        if(remain <= now)
            return false;
        
        for(int i= now+1; i<10; i++)
        {
            temp.push_back(i);
            sum+=i;
            dfs(res, temp, i, sum, k, n);
            sum-=i;
            temp.pop_back();
        }
        return true;
    }
    
};