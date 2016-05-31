class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int *num = new int[len];
        // compute the bit O(n)
        for (int i = 0; i < len; i ++) {
            int k = 0;
            for (int j = 0; j < words[i].length(); j ++) {
                k = k | (1 <<(char)(words[i].at(j)));
            }
            num[i] = k;
        }
        int c = 0;
        // O(n^2)
        for (int i = 0; i < len - 1; i ++) {
            for (int j = i + 1; j < len; j ++) {
                if ((num[i] & num[j]) == 0) { // if no common letters
                    int x = words[i].length() * words[j].length();
                    if (x > c) {
                        c = x;
                    }
                }
            }
        }
        delete []num;
        return c;
    }
};