class Solution {
public:
    struct cmp_struct
    {
        bool operator()(pair<int, int> &l, pair<int, int> &r)
        {
            return l.second > r.second;
        }
    }cmp;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        vector<pair<int, int>> save(k, pair<int,int> (0,0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_struct> pri_que(save.begin(), save.end());
        
        unordered_map<int, int> count_dic;
        for(int i=0; i<len; i++)
            count_dic[nums[i]]++;
        
        for(auto it = count_dic.begin(); it != count_dic.end(); it++)
        {
            if(it->second > pri_que.top().second)
            {
                pri_que.pop();
                pri_que.push(*it);
            }
        }
        vector<int> res;
        while(!pri_que.empty())
        {
            auto it = pri_que.top();
            res.push_back(it.first);
            pri_que.pop();
        }
        
        return res;
    }
};