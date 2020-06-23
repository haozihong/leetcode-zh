class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        diff = functools.reduce(lambda x, y: x^y, nums)
        diff &= -diff  # get the last '1' in binary form
        ans = [0, 0]
        for x in nums:
            ans[bool(x & diff)] ^= x
        return ans