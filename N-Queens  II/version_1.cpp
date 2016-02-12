
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
            
        string none(n,'.');
        vector<string> temp(n, none);
        put_one(res, temp, 0, n);
        
        return res.size();
        
    }
    void put_one(vector<vector<string>> &res, vector<string> &temp, int now, int max)
    {
        if(now == max)
            res.push_back(temp);
        
        for(int i=0; i<max; i++)
        {
            bool flag= true;
            for(int j=0; j<now; j++)
                if(temp[j][i] == 'Q')
                {
                    flag = false;
                    break;
                }
            int x =now, y=i;
            while(x >=0 && y>=0 && flag)
            {
                if(temp[x][y] == 'Q')
                    flag = false;
                --x;
                --y;
            }
            x= now, y =i;
            while(x>=0 && y<max && flag)
            {
                if(temp[x][y] == 'Q')
                    flag =false;
                --x;
                ++y;
            }
            
            if(flag)
            {
                temp[now][i] = 'Q';
                put_one(res, temp, now+1, max);
                temp[now][i] = '.';
            }
        }
        
    }
};