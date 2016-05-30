#第三百零九题
##Best Time to Buy and Sell Stock with Cooldown
中间隔一天，最多获得多少利润

###版本1
写了一个O(n^2)版本的算法， dp[i] = dp[j] +max_one(j+1, i)。利用这个关系，但是超时。

###版本2
记录一个buy一个sell的方法，各有不同含义：使用的第二种方法，详情见如下：

http://bookshadow.com/weblog/2015/11/24/leetcode-best-time-to-buy-and-sell-stock-with-cooldown/