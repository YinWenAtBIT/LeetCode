class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.empty())
            return 0;
        unordered_set<int> existSet;
        unordered_set<int> visitedSet;
        int maxLen =1;
        for(int i = 0; i < num.size(); ++i)
            existSet.insert(num[i]);
        for(int i = 0; i < num.size(); ++i)
        {
            if(visitedSet.find(num[i]) != visitedSet.end())
                continue;
            int count = 1;
            int left = num[i];
            while(existSet.find(--left) != existSet.end())
            {
                ++count;
                visitedSet.insert(left);
            }
            int right = num[i];
            while(existSet.find(++right) != existSet.end())
            {
                ++count;
                visitedSet.insert(right);
            }
            maxLen = maxLen > count ? maxLen : count;
        }
        return maxLen;
    }
};