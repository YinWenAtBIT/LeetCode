class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> res;
        if(!len)
            return res;
        
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        comb_target(candidates, res, comb, target);
    }
    
    void comb_target(vector<int> candidates, vector<vector<int>> &res, vector<int> comb, int target)
    {
        if(target ==0)
        {
            res.push_back(comb);
            return;
        }
        if(!candidates.size())
            return;
            
        int small = candidates[0];
        int num = target/small;
        vector<int> sub(candidates.begin()+1, candidates.end());
        comb_target(sub, res, comb, target);
        for(int i=0; i<num; i++)
        {
            target -=small;
            comb.push_back(small);
            comb_target(sub, res, comb, target);
        }
    }
    
};