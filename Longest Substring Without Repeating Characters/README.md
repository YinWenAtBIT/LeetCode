#第三题
##Longest Substring Without Repeating Characters

求给定字符串中的最长不重复子串的长度。

###版本1
测试得到输入字符都是ascii码，考虑可以用hash的方式做，也可以用简单的set来做，尝试先用set做一个结果，先看看对不对，结果超时了。

###版本2
1. 既然要用hash，肯定有化简的办法，在纸上模拟了几下，发下记录一个字符上一次出现位置，同时记录一个上一次统计长度开始位置（代码里写的laststop），就可以通过一遍遍历得到最长子串，简单修改一下，就成功了，耗时16ms，打败了64.54%。前面只有8%的人用时12ms。感觉找不到优化的地方了，不知道是不是又是运气问题。


![Alt text](https://github.com/YinWenAtBIT/MarkDown_Pic/blob/master/Leetcod_pic/longest_Substring_Without_Repeating_Characters_1.jpg "打败64.54%的对手")


###python版本1：
这个版本完全移植了C++版本的算法，跑了两次，打败86.59%，已经满意了。

![Alt text](https://github.com/YinWenAtBIT/MarkDown_Pic/blob/master/Leetcod_pic/longest_Substring_Without_Repeating_Characters_py.jpg "打败86.59%的对手")