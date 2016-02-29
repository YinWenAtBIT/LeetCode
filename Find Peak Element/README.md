#第一百六十二题
##Find Peak Element

找到峰值，要求在O(lgN)复杂度实现
###版本1
寻找了一下规律，峰值一定在大于Mid的那一边出现，mid和mid-1，mid+1做对比。