class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int len = nums.size();
        if(!len)
        {
            res.push_back(temp);
            return res;
        }
       
        map<int,int> contain;
        for(int i=0; i<len; i++)
            contain[nums[i]]++;
       
       
        combine(res, contain, temp, len, 0);
        return res;
    }
   
    void combine(vector<vector<int>>& res, map<int, int> & contain, vector<int> temp, int total, int cur)
    {
        if(cur == total)
        {
            res.push_back(temp);
            return;
        }
       
        for(map<int, int>::iterator it = contain.begin(); it!= contain.end(); it++)
        {
            if(it->second == 0)
                continue;
               
            temp.push_back(it->first);
            it->second--;
            combine(res, contain, temp, total, cur+1);
            it->second++;
            temp.pop_back();
        }
    }
};