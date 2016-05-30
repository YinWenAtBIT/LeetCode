class NumArray {
private:
    vector<int> c;
    vector<int> m_nums;
public:
    NumArray(vector<int> &nums) {
        c.resize(nums.size() + 1);
        m_nums = nums;
        for (int i = 0; i < nums.size(); i++){
            add(i + 1, nums[i]);
        }
    }

    int lowbit(int pos){
        return pos&(-pos);
    }

    void add(int pos, int value){
        while (pos < c.size()){
            c[pos] += value;
            pos += lowbit(pos);
        }
    }
    int sum(int pos){
        int res = 0;
        while (pos > 0){
            res += c[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    void update(int i, int val) {
        int ori = m_nums[i];
        int delta = val - ori;
        m_nums[i] = val;
        add(i + 1, delta);
    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
};