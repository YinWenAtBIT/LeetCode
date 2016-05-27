class Solution {
public:
    int nthUglyNumber(int n) {
        if(!n)
            return 0;
        vector<int> res(1,1);
        int index1, index2,index3;
        index1 =index2 = index3 =0;
        int out1, out2, out3;
        for(int i=1; i<n; i++)
        {
            out1 = res[index1]*2;
            out2 = res[index2]*3;
            out3 = res[index3]*5;
            int min_out = min(out1, min(out2, out3));
            res.push_back(min_out);
            if(min_out == out1)
                index1++;
            if(min_out == out2)
                index2++;
            if(min_out == out3)
                index3++;
        }
        return res.back();
    }
};