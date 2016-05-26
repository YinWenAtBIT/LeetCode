class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        deque<int> deq;
        
        for(int i=0; i<len; i++)
        {
            while(!deq.empty() && nums[deq.back()] < nums[i])
                deq.pop_back();
            
            deq.push_back(i);
            if(i- deq.front()>=k)
                deq.pop_front();
            
            if(i+1>=k)
                res.push_back(nums[deq.front()]);
        }
        return res;
    }
};