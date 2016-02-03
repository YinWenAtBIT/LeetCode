#第二十三题
##Merge k Sorted Lists

产生括号对

###版本1
自己写了一个顺序遍历，寻找最小值的代码，在vs上可以通过，但是在leetcode上不知道为什么总是runtime error，找不到具体哪里出问题了，暂时放在这里，程序的复杂度为，O(k*N);

###版本2
使用优先队列，降低复杂度为O(N*logK)，但是还是在vs成功，leetcode上runtime error