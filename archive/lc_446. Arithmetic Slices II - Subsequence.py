class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        l = len(A)
        if l < 3: return 0
        d = collections.Counter([A[-1]])
        dp = [collections.defaultdict(int) for _ in range(l-1)]
        for j in range(l - 2, 0, -1):
            for i in range(j):
                t = A[j] - A[i]
                dp[i][t] += d[A[j] + t] + dp[j][t]
            d[A[j]] += 1
        return sum(sum(t.values()) for t in dp)