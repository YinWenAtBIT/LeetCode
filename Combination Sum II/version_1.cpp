class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if(!len)
            return res;
        
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        map<int, int> num_count;
        for(int i=0; i<len; i++)
            num_count[candidates[i]]++;
        vector<int> sub;
        for(auto it = num_count.begin(); it!= num_count.end(); it++)
            sub.push_back(it->first);
        
        
        comb_target(sub, res, comb, num_count, 0, target);
    }
    
    void comb_target(vector<int> &candidates, vector<vector<int>> &res, vector<int> &comb, map<int, int> &num_count, int pos, int target)
    {
        if(target ==0)
        {
            res.push_back(comb);
            return;
        }
        if(pos == candidates.size())
            return;
            
        int small = candidates[pos];

        comb_target(candidates, res, comb, num_count, pos+1, target);
        if(small<=target && num_count[small] >0)
        {
            comb.push_back(small);
            num_count[small]--;
            comb_target(candidates, res, comb, num_count, pos, target-small);
            comb.pop_back();
            num_count[small]++;
        }
    }
};