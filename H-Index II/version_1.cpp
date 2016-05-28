class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(!len)
            return 0;
        int max_h =0;
        get_h(citations, 0, len-1, max_h);
    
        return max_h;
    }
    void get_h(vector<int>& citations, int l, int r, int &max_h)
    {
        if(l>r)
            return;
        int len = citations.size();
        if(l == r)
        {
            int temp = min(citations[l], len -l);
            if(temp>max_h)
                max_h = temp;
            return;
        }
        
        int mid = (l+r)/2;
        int temp = min(citations[mid], len -mid);
        if(temp >max_h)
            max_h = temp;
        
        if(citations[mid] == len-mid)
            return;
        if(temp == citations[mid])
            get_h(citations, mid+1, r, max_h);
        else
            get_h(citations, l, mid-1, max_h);
    }
};