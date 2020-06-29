class Solution:
    def findMaxValueOfEquation(self, A: List[List[int]], k: int) -> int:
        stack = collections.deque()
        mx = -float('inf')
        for x, y in A:
            while stack and x - stack[0][1] > k: stack.popleft()
            if stack: mx = max(mx, stack[0][0] + x + y)
            while stack and stack[-1][0] <= y - x: stack.pop()
            stack.append((y - x, x))
        return mx