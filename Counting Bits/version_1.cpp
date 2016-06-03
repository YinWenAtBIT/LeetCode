class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        
        int start =1;
        int pow_of_two =1;
        int pow_before =1;
        for(;start<=num; start++)
        {
            if(start == pow_of_two)
            {
                res[start] = 1;
                pow_before = pow_of_two;
                pow_of_two = pow_of_two<<1;
                continue;
            }
            res[start] = 1+res[start-pow_before];
        }
        return res;
    }
};