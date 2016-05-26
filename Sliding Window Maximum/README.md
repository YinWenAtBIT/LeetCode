#第二百二十九题
##Sliding Window Maximum

寻找窗口中的最大值，要求O(N)时间内完成

###版本1
使用一个deque，保持deque内的数据是递减的即可。保持的数据超出k范围时就从前方pop。