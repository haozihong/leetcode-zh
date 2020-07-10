# for list [1..n-1], appending n will add 0 inversion part;
# appending n-1 will add 1 inversion part;
# appending n-2 will add 2 inversion parts...
# ....
# f(n, k) = f(n-1, k) + f(n-1, k-1) + ... + f(n-1, max(0, k-n+1))
# f(n, k+1) = f(n-1, k+1) + f(n, k) - (f(n-1, k-n+1) if k-n+1 >= 0)
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MASK = 10**9 + 7
        dp = [1] + [0] * k
        for i in range(2, n+1):
            dp0 = dp.copy()
            for j in range(1, k+1):
                dp[j] += dp[j-1]
                if j - i + 1 > 0: dp[j] -= dp0[j-i]
                dp[j] %= MASK
        return dp[-1]