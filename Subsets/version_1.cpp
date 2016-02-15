class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(!len)
            return res;
        
        sort(nums.begin(), nums.end());
        vector<bool> flag(len, false);
        vector<int> temp;
        for(int i=0; i<=len; i++)
        {
            temp.clear();
            dfs(res, nums, flag, temp, 0, 0, i);
        }
        return res;
        
    }
    void dfs(vector<vector<int>> &res, vector<int>& nums, vector<bool> &flag, vector<int> &temp, int now, int start, int k)
    {
        if(now == k)
        {
            res.push_back(temp);
            return;
        }
        
        int len = nums.size();
        if(k-now > len -start)
            return;
        for(int i=start; i<len; i++)
        {
            if(!flag[i])
            {
                flag[i] =true;
                temp.push_back(nums[i]);
                dfs(res, nums, flag, temp, now+1, i+1, k);
                flag[i] = false;
                temp.pop_back();
            }
        }
    }
};