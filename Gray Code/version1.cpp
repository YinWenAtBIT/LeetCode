class Solution
{
public:
    /*
     * for reference: http://en.wikipedia.org/wiki/Gray_code.
     */
    vector<int> grayCode (int n) {
        
        int size = 1 << n;
        vector<int> ret(size);
        for (int i = 0; i < size; i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};