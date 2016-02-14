class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry =1;
        while(carry && len)
        {
            digits[len -1] += carry;
            carry = digits[len -1]/10;
            digits[len -1] = digits[len -1] %10;
            len --;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};