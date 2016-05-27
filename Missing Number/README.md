#第二百六十八题
##Missing Number
找到n个数字中，从0-n之间少的那个数字

###版本1
这题和first missing positive number很相似，解法也是一样的，将数字i+1放在位置nums[i]上，最后遍历是否满足nums[i] == i+1;
如果都满足则是0不见了。