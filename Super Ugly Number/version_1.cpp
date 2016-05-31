class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)
            return 1;
        int len = primes.size();
        vector<int> index(len, 0);
        vector<int> res(1,1);
        for(int i=1; i<n; i++)
        {
            vector<int> temp_arr;
            int min_now =INT_MAX;
            for(int j=0; j<len; j++)
            {
                int temp = res[index[j]] *primes[j];
                temp_arr.push_back(temp);
                if(min_now>temp)
                    min_now = temp;
            }
            res.push_back(min_now);
            for(int j=0; j<len; j++)
                if(temp_arr[j] == min_now)
                    index[j]++;
            
            
        }
        return res.back();
    }
};