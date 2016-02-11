class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
       
        int len = nums.size();
        if(!len)
            return res;
       
        set<int> contain;
        for(int i=0; i<len; i++)
            contain.insert(nums[i]);
        vector<int> temp;
        combine(res, contain, temp);
        return res;
    }
   
    void combine(vector<vector<int>>& res, set<int> & contain, vector<int> temp)
    {
        if(contain.empty())
        {
            res.push_back(temp);
            return;
        }
       
        for(set<int>::iterator it = contain.begin(); it!= contain.end(); it++)
        {
            int now_num = *it;
            temp.push_back(now_num);
            contain.erase(now_num);
            combine(res, contain, temp);
            contain.insert(now_num);
            temp.pop_back();
        }
    }
};