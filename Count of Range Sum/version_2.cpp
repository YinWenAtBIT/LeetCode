class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        sums = nums[:]
        for x in range(1, len(sums)):
            sums[x] += sums[x - 1]
        osums = sorted(set(sums))
        ft = FenwickTree(len(osums))
        ans = 0
        for sumi in sums:
            left = bisect.bisect_left(osums, sumi - upper)
            right = bisect.bisect_right(osums, sumi - lower)
            ans += ft.sum(right) - ft.sum(left) + (lower <= sumi <= upper)
            ft.add(bisect.bisect_right(osums, sumi), 1)
        return ans

class FenwickTree(object):
    def __init__(self, n):
        self.n = n
        self.sums = [0] * (n + 1)
    def add(self, x, val):
        while x <= self.n:
            self.sums[x] += val
            x += self.lowbit(x)
    def lowbit(self, x):
        return x & -x
    def sum(self, x):
        res = 0
        while x > 0:
            res += self.sums[x]
            x -= self.lowbit(x)
        return res