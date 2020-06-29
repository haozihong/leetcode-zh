from heapq import *
class Solution:
    def findMaxValueOfEquation(self, A: List[List[int]], k: int) -> int:
        hp = []
        mx = -float('inf')
        for x, y in A:
            while hp and hp[0][1] < x - k: heappop(hp)
            if hp: mx = max(mx, x + y - hp[0][0])
            heappush(hp, (x-y, x))
        return mx