class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        
        if(k<len/2)
        {
            priority_queue<int> res(nums.begin(), nums.end());
            for(int i=0; i<k-1; i++)
                res.pop();
            return res.top();
        }
        else
        {
            priority_queue<int, std::vector<int>, std::greater<int> > res(nums.begin(), nums.end());
            int rev= len -k+1;
            for(int i=0; i<rev-1; i++)
                res.pop();
            return res.top();
        }
        
    }
};