#第四题
##Median of Two Sorted Arrays

求两个已排序数组的中位数。

###版本1
最直白的两个索引按序增加，知道达到中间。打败78.94%，但是看题目标签是困难，我这个做法简直不可思议的快速，觉得不太可能，点开了题目的标签，发现有分治算法和二叉树。觉得应该可以有更快的算法。

###版本2
知道了分治算法之后，想了一会儿就想到取中值的做法，手贱想查查通过二叉树怎么做的，结果没有，但是看了我想的分治算法的代码，不过最初的实现是通过数组，而不是vector，但是思路是一样的。很快就写出了版本2，结果时间一样，醉了，O(m+n)和O(log(m+n))用时相同，leetcode的runtime真是不太准。不过这次代码是做了两次递归，实际上是浪费了一半性能的，改写一下试试效果。

###版本3
版本2的分治算法，在总数为偶数时，计算了两次，topk，多做了一次递归，我给改成了增加一个flag，flag为1时，正常求topk，flag为0时，求topk和topk+1的均值。结果时间丝毫没有改变，只能说，我服了。

![Alt text](https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/median_of_two_sorted_arrays.jpg "打败78.94%的对手")


###python版本：
现在决定不要再写python版本了，算法使用一样，还不如学学python 的新东西。
