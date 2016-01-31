class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len <2)
            return res;
            
        vector<int> one_ans(3);
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        for(int i=0; i<len-2; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
                
            vector<int> sub(nums.begin()+i+1, nums.end());
            set<pair<int, int>> temp = twoSum(sub, 0-nums[i]);
            for(auto &x: temp)
            {
                one_ans[0] = nums[i];
                one_ans[1] = x.first;
                one_ans[2] = x.second;
                res.push_back(one_ans);
            }
        }
        return res;
    }

    set<pair<int, int>> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> mp;
        map<int, int>::iterator pt;
        vector<vector<int>> res;
        set<pair<int, int>> numpair;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++) {
            pt = mp.find(target - numbers[i]);
            if (pt != mp.end()) {
                pair<int, int> temp(pt->first, numbers[i]);
                if(numpair.find(temp) == numpair.end())
                    numpair.insert(temp);
            }
            else{
                mp[ numbers[i] ] = i + 1;
            }
        }
        return numpair;
    }
};