class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len <4)
            return res;
            
        sort(nums.begin(), nums.end());
        vector<vector<int>> thr_ans;
        for(int i=0; i<len-3; i++)
        {
            if(i >0 && nums[i] == nums[i-1])
                continue;
                
            vector<int> temp(nums.begin()+i+1, nums.end());
            thr_ans = threeSum(temp, target-nums[i]);
            int ans_len = thr_ans.size();
            for(int j=0; j<ans_len; j++)
                thr_ans[j].insert(thr_ans[j].begin(), nums[i]);
            res.insert(res.end(), thr_ans.begin(), thr_ans.end());
        }
        
        return res;
        
        
    }
    
     vector<vector<int> > threeSum(vector<int> &num, int target) {
         int n = num.size();

         vector<vector<int> > res;
         for(int i = 0; i < n-2; i++)
         {
             if(i > 0 && num[i] == num[i-1])continue;//重复的元素不用计算
            int target2 = target - num[i];
            twoSum(num, i+1, target2, res);
        }
        return res;
    }
    
     void twoSum(vector<int> &sortedNum, int start, int target, vector<vector<int> >&res)
     {
         int head = start, tail = sortedNum.size() - 1;
         while(head < tail)
         {
             int tmp = sortedNum[head] + sortedNum[tail];
             if(tmp < target)
                 head++;
             else if(tmp > target)
                 tail--;
             else
             {
                 res.push_back(vector<int>{sortedNum[start-1], sortedNum[head], sortedNum[tail]});
                 
                 //为了防止出现重复的二元组，使结果等于target
                 int k = head+1;
                 while(k < tail && sortedNum[k] == sortedNum[head])k++;
                 head = k;
                 
                 k = tail-1;
                 while(k > head && sortedNum[k] == sortedNum[tail])k--;
                 tail = k;
             }
         }
     }
};