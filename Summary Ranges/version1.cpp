class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        if(!len)
            return res;
        
        bool start = false;
        for(int i=0; i<len; i++)
        {
            start = false;
            string temp = to_string(nums[i]);
            while(i+1<len && nums[i+1]-nums[i] ==1)
            {
                i++;
                start = true;
            }
            if(start)
                temp+="->"+to_string(nums[i]);
            res.push_back(temp);
        }
        return res;
    }
    
};