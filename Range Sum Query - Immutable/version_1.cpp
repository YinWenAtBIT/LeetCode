class NumArray {
private:
    vector<int> acc;
    
public:
    NumArray(vector<int> &nums) {
        acc.push_back(0);
        for (auto n : nums) {
            acc.push_back(acc.back() + n);
        }
    }

    int sumRange(int i, int j) {
        return acc[j + 1] - acc[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
