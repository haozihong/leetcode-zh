class Solution:
    def maxCoins(self, A: List[int]) -> int:
        @functools.lru_cache(None)
        def f(l, r):  # balloon l+1 ~ r-1 are all burst
            if l + 1 >= r: return 0
            return max(f(l,i) + f(i,r) + A[l]*A[i]*A[r] for i in range(l+1, r))  # loop for i as the last one to be burst
        A.append(1)  # make A[-1] and A[n] equals to 1
        return f(-1, len(A)-1)