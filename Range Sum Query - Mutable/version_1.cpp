class NumArray {
public:
    NumArray(vector<int> &nums) {
        int len = nums.size();
        save = nums;
        if(!len)
            return;
        sum.push_back(0);
        for(int i=0; i<len; i++)
            sum.push_back(sum.back()+nums[i]);
    }

    void update(int i, int val) {
        int bef = save[i];
        int diff = val - bef;
        save[i] = val;
        for(int j=i+1; j<sum.size(); j++)
            sum[j] += diff;
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
private:
    vector<int> sum;
    vector<int> save;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);