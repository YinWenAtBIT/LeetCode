class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> before;
        before.assign(1,1);
        if(!rowIndex)
            return before;
        vector<int> now;
        for(int i=2; i<=rowIndex +1; i++)
        {
            now.assign(i,1);
            for(int j=1; j<i-1; j++)
                now[j] = before[j-1]+before[j];
            before = now;
        }
        return before;
    }
};