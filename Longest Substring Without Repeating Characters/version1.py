class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length= len(s)
        if length == 0:
            return 0
        flag = [0]*128
        lastAppear = flag[:]
        max =1
        laststop = 0
        
        
        for i in range(length):
            ascii = ord(s[i])
            if not flag[ascii]:
                flag[ascii] = 1
                lastAppear[ascii] = i;
            else:
                if lastAppear[ascii] < laststop:
                    lastAppear[ascii] = i
                else:
                    lastlength = i - laststop
                    if lastlength > max:
                        max = lastlength
                    
                    laststop = lastAppear[ascii]+1
                    lastAppear[ascii] = i
            
        lastlength = length - laststop
        if lastlength > max:
            max = lastlength
        return max