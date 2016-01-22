#第二题
##Add Two Numbers

在链表中放入两个数，每个节点是一位，逆序排列。结果放回列表。

###版本1
第一个版本，先判断哪个列表长，然后在长的列表中进行运算，结果只打败了21%的对手。看来必须只进行一遍访问。

###版本2
1. 最开始只改成了一遍访问，结果速度几乎没有提升，于是只能怀疑微小的细节提升了。把减法改成减等于，判断能不比较久不比较，然后提升了4ms，排名69.99%。

###版本3
尝试了几个版本之后，结果都不稳定了，在36ms -44ms之间徘徊，不过看我自己的代码，感觉应该已经找不到优化的地方了，在36ms之前也就只剩下很少一部分人了，可能是由于运气跑到前面的吧^_^

![Alt text](https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/add_two_numbers.jpg "打败69.99的对手")

###python版本1：
完全的C++版本算法移植，第一遍148ms，打败44%，我打算超过50%就算了，于是再跑了一遍，结果打败了93.68%，果然运行时间太不靠谱了。。

![Alt text](https://raw.githubusercontent.com/YinWenAtBIT/MarkDown_Pic/master/Leetcod_pic/add_two_numbers_py.jpg"打败93.68的对手")