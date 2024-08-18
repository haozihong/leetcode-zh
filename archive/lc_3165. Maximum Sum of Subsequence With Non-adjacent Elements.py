# Array, Divide and Conquer, Dynamic Programming, Segment Tree

M = 10**9 + 7

class SegTree:
    def __init__(self, l, r):
        assert(l < r)
        self.l, self.r = l, r
        self.l0r0 = self.l1r0 = self.l0r1 = self.l1r1 = 0
        if r - l > 1:
            m = (l + r) // 2
            self.c = SegTree(l, m), SegTree(m, r)
    
    def set(self, idx, val):
        assert(self.l <= idx < self.r)
        if self.r - self.l <= 1:
            self.l0r0 = max(val, 0)
            return
        m = (self.l + self.r) // 2
        self.c[idx >= m].set(idx, val)
        self.l0r0 = max(self.c[0].l0r1 + self.c[1].l1r0, self.c[0].l0r0 + self.c[1].l1r0, self.c[0].l0r1 + self.c[1].l0r0)
        self.l1r0 = max(self.c[0].l1r1 + self.c[1].l1r0, self.c[0].l1r0 + self.c[1].l1r0, self.c[0].l1r1 + self.c[1].l0r0)
        self.l0r1 = max(self.c[0].l0r1 + self.c[1].l1r1, self.c[0].l0r0 + self.c[1].l1r1, self.c[0].l0r1 + self.c[1].l0r1)
        self.l1r1 = max(self.c[0].l1r1 + self.c[1].l1r1, self.c[0].l1r0 + self.c[1].l1r1, self.c[0].l1r1 + self.c[1].l0r1)

class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        seg = SegTree(0, len(nums))
        for i, x in enumerate(nums):
            seg.set(i, x)
        res = 0
        for i, x in queries:
            seg.set(i, x)
            res = (res + seg.l0r0) % M
        return res