class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(!len)
            return 0;
        sort(citations.begin(), citations.end());
        int max_h=0;
        for(int i=0; i<len; i++)
        {
            int temp = min(citations[i], len -i);
            if(max_h<temp)
                max_h = temp;
        }
        return max_h;
    }
};