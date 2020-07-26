class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l < r:
            if nums[l] < nums[r]: break
            m = (l+r)//2
            if nums[l] == nums[m] == nums[r]:
                l += 1
                r -= 1
            elif nums[m] >= nums[l]:
                l = m + 1
            else:
                r = m
        return nums[l]