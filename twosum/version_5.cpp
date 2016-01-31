class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &numbers, int target) {
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
                {
                    numpair.insert(temp);
                    ans.push_back(pt->second);
                    ans.push_back(i + 1);
                    res.push_back(ans);
                    ans.clear();
                }
            }
            else{
                mp[ numbers[i] ] = i + 1;
            }
        }
        return res;
    }
};