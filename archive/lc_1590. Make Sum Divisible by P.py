# Array, Binary Search?, Hash Table

class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        t = sum(nums) % p
        if t == 0: return 0
        ss = 0
        d = {0: -1}
        mn = n = len(nums)
        for i, x in enumerate(nums):
            ss = (ss + nums[i]) % p
            d[ss] = i
            t2 = (ss - t + p) % p
            if t2 in d: mn = min(mn, i - d[t2])
        return mn if mn < n else -1