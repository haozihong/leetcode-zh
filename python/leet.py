import math, itertools, collections, functools, bisect, heapq, random
from typing import List

from leet_binary_tree import *
from leet_linked_list import *
from leet_tools import *
import leet_ins

class Solution:
    def hIndex(self, A: List[int]) -> int:
        l, r, lng = 0, len(A), len(A)
        while l < r:
            m = (l + r)//2
            if A[m] - (lng - m) >= 0: r = m
            else: l = m + 1
            print(l, r)
        return lng - l

def main():
    # in0 = [7,[-1,0,0,1,1,2,2]]
    # in1 = [[3,1],[5,2],[6,3]]
    ins = [
        [2,10]
    ]
    ou = Solution().hIndex(*ins)
    # ou = Solution().hIndex(*leet_ins.ins)
    print(ou)

    # timeit(Solution().distributeCoins)

if __name__ == "__main__":
    main()
