class Solution:
    def numTrees(self, n: int) -> int:
        a = [1, 1] + [0] * (n - 1)
        for i in range(2, n+1):
            for j in range(i):
                a[i] += a[j] * a[i-1-j]
        return a[n]