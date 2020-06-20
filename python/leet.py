import math, itertools, collections, functools, bisect, heapq, random
from typing import List

from leet_binary_tree import *
from leet_linked_list import *
from leet_tools import *
import leet_ins

class Solution:
    def longestDupSubstring(self, S: str) -> str:
        lng = len(S)
        A = [ord(c) - 97 for c in S]
        M, MOD = 5, 10000000007
        def search(l):
            if l == 0: return None
            ha = functools.reduce(lambda x, y: ((x<<M) + y)% MOD, A[:l])
            ss = {ha}
            for i in range(1, lng-l+1):
                ha = (((ha - (A[i-1]<<M*(l-1)))<<M) + A[i+l-1])% MOD
                if ha in ss: return i
                ss.add(ha)
        res, l, r = 0, 0, lng
        while l + 1 < r:
            m = (l + r) // 2
            p = search(m)
            if p: l, res = m, p
            else: r = m
        return S[res:res+l]
    def longestDupSubstring2(self, S: str) -> str:
        lng = len(S)
        A = [ord(c) - 97 for c in S]
        M, MOD = 26, (1<<63)-1
        def search(l):
            if l == 0: return None
            ha = functools.reduce(lambda x, y: (x*M + y)% MOD, A[:l])
            ss = {ha}
            t = pow(M, l-1, MOD)
            for i in range(1, lng-l+1):
                ha = ((ha - A[i-1]*t)*M + A[i+l-1])% MOD
                if ha in ss: return i
                ss.add(ha)
        res, l, r = 0, 0, lng
        while l + 1 < r:
            m = (l + r) // 2
            p = search(m)
            if p: l, res = m, p
            else: r = m
        return S[res:res+l]

def main():
    # in0 = [7,[-1,0,0,1,1,2,2]]
    # in1 = [[3,1],[5,2],[6,3]]
    ins = [
        "abcd"
    ]
    ins = leet_ins.ins
    ou = Solution().longestDupSubstring2(*ins)
    print(ou)

    # timeit(Solution().distributeCoins)

if __name__ == "__main__":
    main()
