#第三百零九题
##Best Time to Buy and Sell Stock with Cooldown
中间隔一天，最多获得多少利润

###版本1
写了一个O(n^2)版本的算法， dp[i] = dp[j] +max_one(j+1, i)。利用这个关系，但是超时。

###版本2
使用树状数组实现，查询和修改复杂度都为O(lgn)