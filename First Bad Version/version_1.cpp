// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(!n)
            return 0;
        long long int start =(long long int)n+1;
        find_bad(1, n, start);
        return start;
    }
    void find_bad(long long int l, long long int r, long long int &start)
    {
        if(l>r)
            return;
        if(l == r)
        {
            if(isBadVersion(l) && l<start)
                start = l;
            return;
        }
        
        long long int mid = (l+r)/2;
        if(isBadVersion(mid))
        {
            if(mid<start)
                start = mid;
            find_bad(l, mid-1, start);
        }
        else
            find_bad(mid+1, r, start);

    }
};