 class Solution {
 public:
     vector<vector<int> > threeSum(vector<int> &num) {
         int n = num.size();
         sort(num.begin(), num.end());
         vector<vector<int> > res;
         for(int i = 0; i < n-2; i++)
         {
             if(i > 0 && num[i] == num[i-1])continue;//重复的元素不用计算
            int target2 = 0 - num[i];
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