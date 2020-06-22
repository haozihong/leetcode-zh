
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # use 2 bits as a counter for each bit
        # should loop through 00->01->10->00 when countings
        bit0, bit1 = 0, 0
        for x in nums:
            bit0 ^= x & ~bit1
            bit1 ^= x & ~bit0
        return bit0