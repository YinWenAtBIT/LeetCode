class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if(!len)
            return res;
        
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        comb_target(candidates, res, comb, 0, target);
    }
    
    void comb_target(vector<int> &candidates, vector<vector<int>> &res, vector<int> &comb, int pos, int target)
    {
        if(target ==0)
        {
            res.push_back(comb);
            return;
        }
        if(pos == candidates.size())
            return;
            
        int small = candidates[pos];

        comb_target(candidates, res, comb, pos+1, target);
        if(small<=target)
        {
            comb.push_back(small);
            comb_target(candidates, res, comb, pos, target-small);
            comb.pop_back();
        }
    }
    
};