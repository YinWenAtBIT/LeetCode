#第一百九十二题
##House Robber
计算最大抢劫金额，相邻的两家不能被抢。
###版本1
使用动态规划   
dp[i] =max(dp[i-3] +nums[i], dp[i-2] +nums[i]);
dp[i]代表第i家一定要抢的最大金额。
最后在dp[len-2]与dp[len-1]中返回一个最大值即可