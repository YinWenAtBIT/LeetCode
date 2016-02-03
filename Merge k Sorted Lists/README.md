#第二十三题
##Merge k Sorted Lists

合并K个已排序链表

###版本1
自己写了一个顺序遍历，寻找最小值的代码，在vs上可以通过，但是在leetcode上不知道为什么总是runtime error，找不到具体哪里出问题了，暂时放在这里，程序的复杂度为，O(k*N);

晚上可以通过了，但是运行超时，需要加快寻找k中最小值的速度。

###版本2
使用优先队列，降低复杂度为O(N*logK)，但是还是在vs成功，leetcode上runtime error

晚上可以通过了，leetcode原来抽风了。