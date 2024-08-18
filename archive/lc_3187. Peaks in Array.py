# Array, Binary Indexed Tree, Segment Tree

class Node:
    def __init__(self, l, r, data):
        self.l, self.r, self.data = l, r, data
        self.m = (l + r) // 2
        if r - l <= 1:
            self.v = 0 < l < len(data) - 1 and data[l-1] < data[l] > data[l+1]
        else:
            self.c = Node(l, self.m, data), Node(self.m, r, data)
            self.v = self.c[0].v + self.c[1].v
    
    def set(self, idx, val):
        if self.r - self.l <= 1:
            l, data = self.l, self.data
            data[idx] = val
            self.v = 0 < l < len(data) - 1 and data[l-1] < data[l] > data[l+1]
            return
        if idx - 1 < self.m: self.c[0].set(idx, val)
        if self.m <= idx + 1: self.c[1].set(idx, val)
        self.v = self.c[0].v + self.c[1].v
    
    def query(self, l, r):
        if l <= self.l and self.r <= r: return self.v
        res = 0
        if l < self.m: res += self.c[0].query(l, r)
        if self.m < r: res += self.c[1].query(l, r)
        return res

class Solution:
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        seg = Node(0, len(nums), nums)
        res = []
        for t, t1, t2 in queries:
            if t == 2: seg.set(t1, t2)
            else: res.append(seg.query(t1 + 1, t2))
        return res