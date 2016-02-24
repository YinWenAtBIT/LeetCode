#第一百三十八题
##Copy List with Random Pointer
深度复制带有random指针的链表

###版本1
基本约等于穷举，结果没超时，做完就想到如何使用map来匹配的方法了。
用时456ms，再多4ms超时。

###版本2
使用unordered_map,记录原链表与新链表的每个节点的匹配关系，然后可以直接找到random指向的新节点