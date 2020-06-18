class Solution:
    def hIndex(self, A: List[int]) -> int:
        l, r, lng = 0, len(A), len(A)
        while l < r:
            m = (l + r)//2
            if A[m] - (lng - m) >= 0: r = m
            else: l = m + 1
        return lng - l