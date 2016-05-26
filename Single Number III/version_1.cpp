class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int AxorB = 0;
        for(int i = 0;i<nums.size();i++){
            AxorB^=nums[i];
        }
        //取最后一个二进制位
        int mask = AxorB & (~(AxorB-1));
        int A = 0,B = 0;
        for(int i = 0;i<nums.size();i++){
            if(mask&nums[i])
                A ^= nums[i];
            else
                B ^= nums[i];
        }

        return vector<int>({A,B});
    }
};