class Solution:
    '''Binary search; DP'''
    def calculateMinimumHP(self, A: List[List[int]]) -> int:
        MIN = -float('inf')
        m, n = len(A), len(A[0])
        t, mn = 0, 0
        for j in range(n):
            t += A[0][j]
            if t < mn: mn = t
        for i in range(1, m):
            t += A[i][-1]
            if t < mn: mn = t
        l, r = 1, max(1, -mn + 1)
        while l < r:
            mid = (l+r)//2
            dp = [mid] + [MIN] * (n-1)
            for i in range(m):
                dp2 = [dp[0] + A[i][0]] + [0] * (n-1)
                if dp2[0] <= 0: dp2[0] = MIN
                for j in range(1, n):
                    dp2[j] = max(dp2[j-1], dp[j]) + A[i][j]
                    if dp2[j] <= 0: dp2[j] = MIN
                dp = dp2
            if dp[-1] >= 1: r = mid
            else: l = mid + 1
        return l