class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        if(!n)
            return res;
        
        for(int i=0; i<n; i++)
            res[i].assign(n,0);
            
        
        int cycle = n/2;
        int start =1;
        int k;
        for(int i=0; i<cycle; i++)
        {
            for(int j=i; j<n-i; j++)
            {
                res[i][j] = start;
                ++start;
            }
            k = n-1-i;
            for(int j = i+1; j<n-1-i; j++)
            {
                res[j][k] = start;
                ++start;
            }
            for(int j=n-1-i; j>i; j--)
            {
                res[k][j] = start;
                ++start;
            }
            for(int j = n-1-i; j>i; j--)
            {
                 res[j][i] = start;
                ++start;               
            }
        }
        if(n%2)
            res[n/2][n/2] = start;
        return res;
    }
};