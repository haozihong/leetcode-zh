# DP

class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        c = math.comb
        n = len(nums)
        d = [0] * n
        for i, x in enumerate(nums): d[x-1] = i
        ans = 1
        que = collections.deque([(0, 0, n+1)])  # i, l, r
        while que:
            i, l, r = que.popleft()
            ans *= c(r - l - 2, nums[i] - l - 1)
            if l + 1 < nums[i]:
                que.append((min(d[l:nums[i]-1]), l, nums[i]))
            if nums[i] + 1 < r:
                que.append((min(d[nums[i]:r-1]), nums[i], r))
        return (ans - 1) % MOD