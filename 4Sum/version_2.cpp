class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len<4)
            return res;
            
        sort(nums.begin(), nums.end());
        map<int, list<pair<int, int>>> mp;
        
        for(int i=0; i< len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                pair<int, int> temp(nums[i], nums[j]);
                int sum = nums[i] + nums[j];
                if(mp.find(target-sum) != mp.end())
                {
                    list<pair<int, int>> & before = mp[target-sum];
                    for(list<pair<int, int>>::iterator it = before.begin(); it != before.end(); it++)
                    {
                        vector<int> ans;
                        ans.push_back(it->first);
                        ans.push_back(it->second);
                        ans.push_back(temp.first);
                        ans.push_back(temp.second);
                        sort(ans.begin(), ans.end());
                        res.push_back(ans);
                    }
                    
                    if(mp.find(sum) != mp.end())
                    {
                        list<pair<int, int>> & before = mp[sum];
                        before.push_back(temp);
                    }
                    else
                    {
                        list<pair<int, int>> new_one;
                        new_one.push_back(temp);
                        mp[sum] = new_one;
                    }                    
                }
                else
                {
                    if(mp.find(sum) != mp.end())
                    {
                        list<pair<int, int>> & before = mp[sum];
                        before.push_back(temp);
                    }
                    else
                    {
                        list<pair<int, int>> new_one;
                        new_one.push_back(temp);
                        mp[sum] = new_one;
                    }
                }
            }
            
        return res;
    }
};