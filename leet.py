from leet_binary_tree import *
from leet_linked_list import *
import leet_ins
import math, itertools, collections, functools, bisect, heapq
import time, random

def print_line(a):
    for l in a:
        for ch in l:
            print("{:2}".format(ch),end = ",")
        print()

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
        return mn

    def shortestSubarray2(self, A, K: int) -> int:
        n = len(A)
        mn = n + 1
        i, j, t, prev_t = 0, 0, 0, 0
        while 1:
            t = 0
            j = i
            while j < n and t < K:
                t += A[j]; j += 1
                if t < 0: t, i = 0, j
            print(i, j,j-i, t)
            if t < K: break
            # prev_t = t
            if j - i < mn: mn = j - i
            i += 1
            while i < j and A[i] < 0: i += 1
        return mn if mn <= n else -1

def main():
    # in0 = [7,[-1,0,0,1,1,2,2]]
    # in1 = [[3,1],[5,2],[6,3]]
    # ins = []
    # ou = Solution().shortestSubarray(*leet_ins.ins)
    fn = Solution().shortestSubarray
    ou = fn(*leet_ins.ins)
    print(ou)


    def timeit(fn):
        tt = 5
        s = time.time()
        for i in range(tt):
            ou = fn(stringToTreeNode(in0))
        print(ou)
        print("1:", time.time() - s)
    # timeit(Solution().distributeCoins)
    # timeit(Solution().distributeCoins2)


if __name__ == "__main__":
    main()
