import math, itertools, collections, functools, bisect, heapq, random

from leet_binary_tree import *
from leet_linked_list import *
from leet_tools import *
import leet_ins

class Solution:
    def shortestSubarray(self, A, K: int) -> int:
        n = len(A)
        mn = n + 1
        t, que, d = 0, [0], {0: -1}
        for i, x in enumerate(A):
            t += x
            p = bisect.bisect_right(que, t - K) - 1
            if p >= 0:
                mn = min(mn, i - d[que[p]])
            while que and que[-1] >= t: que.pop()
            que.append(t)
            d[t] = i
        return mn if mn <= n else -1

def main():
    # in0 = [7,[-1,0,0,1,1,2,2]]
    # in1 = [[3,1],[5,2],[6,3]]
    # ins = []
    ou = Solution().shortestSubarray(*leet_ins.ins)
    print(ou)

    # timeit(Solution().distributeCoins)
    # timeit(Solution().distributeCoins2)

if __name__ == "__main__":
    main()
