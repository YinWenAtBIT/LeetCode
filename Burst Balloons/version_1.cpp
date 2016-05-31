class Solution {
public:
    int maxCoins(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        int n=nums.size();
        if(n==0) return 0;
        //if(n==1) return nums[0];
        //if(n==2) return nums[0]*nums[1]+max(nums[0],nums[1]);
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int m=nums.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int count=1;count<=n;++count){
            for(int start=1;start+count-1<=n;++start){
                int bestcoins=0;
                for(int b=0;b<count;++b){
                    bestcoins=max(bestcoins,dp[start][start+b-1]+nums[start-1]*nums[start+b]*nums[start+count]+dp[start+b+1][start+count-1]);

                }
                dp[start][start+count-1]=bestcoins;
            }

        }
        return dp[1][n];
    }
};