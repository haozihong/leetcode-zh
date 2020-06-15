class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums: return []
        nums.sort()
        dp = [(1, -1)] * len(nums)
        mxi = 0
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and dp[j][0] + 1 > dp[i][0]:
                    dp[i] = (dp[j][0]+1, j)
                if dp[i][0] > dp[mxi][0]: mxi = i
        ans, p = [], mxi
        while p != -1:
            ans.append(nums[p])
            p = dp[p][1]
        ans.reverse()
        return ans