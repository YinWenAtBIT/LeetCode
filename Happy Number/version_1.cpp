class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> his;
        while(his.find(n)==his.end() & n !=1)
        {
            his.insert(n);
            int temp=0;
            int new_one=0;
            while(n)
            {
                temp = n %10;
                n= n/10;
                new_one += temp*temp;
            }
            n = new_one;
        }
        return n==1;
    }
};