#第一题
##Two Sum

给定一个数组和一个数，求这个数组中两个数的和等于给定数的下标+1，要求小下标在前。结果保存在vector<int>中。

###版本1
由于这是第一次刷题，没有想太多，直接用一个两重循环解了出来，未考虑太多，直接accept,时间580ms，打败了最后15%的人。

###版本2
1. 想到求和可以利用hash函数，设定一个记录表即可，判断记录表是否已经被占据，就可以得到结果。 结果accept失败，一看忘记考虑负数了。
2. 修改新的挺简单，想了几分钟，使用一个负数记录表，一个正数记录表，发现被占后，判断正负记录表，原位置和与目标的差位置是否有所求结果，顺利一遍通过。
3. 第一题就打败了97.85%的人（感觉最前面的5%都在一起，说不定是运行速度问题的差别，嘻嘻），而且就是在线编程，没有使用ide，给我很多信心！

###版本3
妄想以舍弃vector, 手动开辟内存空间的办法来加速，结果排名丝毫未变，好想知道比我快的人是用了什么更屌（奇技淫巧！）的优化方式。

[id]:https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/two_sum_version2.jpg "打败97.85的对手"

![Alt text](https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/two_sum_version2.jpg "打败97.85的对手")

###python版本1：
这个版本完全移植了C++版本的算法，可惜由于对于python一直是用的时候学习，对于如何写出高性能的python代码并不懂，结果落在了最高峰处，只打败了50%多的人

![Alt text](https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/two_sum_version_1_python.jpg "打败56.78的对手")