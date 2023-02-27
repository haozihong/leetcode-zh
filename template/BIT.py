class BIT:
    '''BIT of a[1..n], 1-based indexing'''

    def __init__(self, n, arr=None):
        if arr is not None: 
            self.n, self.c = len(arr), [0] + arr
            for i in range(1, self.n+1):
                if (j := i + BIT.lowbit(i)) <= self.n:
                    self.c[j] += self.c[i]
        else:
            self.n, self.c = n, [0] * (n + 1)
    
    def lowbit(x): return x & -x

    def add(self, p, v=1):
        '''1-based indexing'''
        while p <= self.n:
            self.c[p] += v
            p += BIT.lowbit(p)

    def prefix_sum(self, r):
        '''sum of a[1..r], 1-based indexing'''
        res = 0
        while r > 0:
            res += self.c[r]
            r -= BIT.lowbit(r)
        return res

    def range_sum(self, l, r):
        '''sum of a[l..r], 1-based indexing'''
        return self.prefix_sum(r) - self.prefix_sum(l-1)
    
    def get_val(self, p):
        '''value of a[p], 1-based indexing'''
        return self.range_sum(p, p)

# 1649. Create Sorted Array through Instructions
class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        n = max(instructions)
        b = BIT(n)
        res = 0
        for i, x in enumerate(instructions):
            res = (res + min(b.prefix_sum(x-1), i - b.prefix_sum(x))) % (10**9+7)
            b.add(x)
        return res