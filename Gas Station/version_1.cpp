class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        if(!len)
            return -1;
        int have =0;
        int need = 0;
        vector<int> remain(len);
        for(int i=0; i<len; i++)
        {
            have +=gas[i];
            need +=cost[i];
            remain[i] = gas[i] - cost[i];
        }
        if(have<need)
            return -1;
        int sum =0;
        int max_start =-1;
        int max_remain = -1;
        int last_start =0;
        int pos = 0;
        bool flag = false;
        while(1)
        {
            sum+=remain[pos];
            if(sum > max_remain)
            {
                max_remain = sum;
                max_start = last_start;
            }
            if(sum<=0)
            {
                sum =0;
                last_start = (pos+1)%len;
            }
            pos++;
            if(pos == len)
            {
                if(!flag)
                {
                    flag = true;
                    pos = 0;
                }
                else
                    break;
            }
        }
        return max_start;
    }
};