class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(), 1);
        int height = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = max(++height, candy[i]);
            } else {
                height = 1;
            }
        }
        height = 1;
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(++height, candy[i]);
            } else {
                height = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < ratings.size(); i++) {
            ans += candy[i];
        }
        return ans;
    }
};