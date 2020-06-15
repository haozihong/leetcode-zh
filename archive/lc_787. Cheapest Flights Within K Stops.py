class Solution:
    def findCheapestPrice(self, n: int, A: List[List[int]], src: int, dst: int, K: int) -> int:
        vs = [[] for _ in range(n)]
        for u, v, w in A:
            vs[u].append((v, w))
        d = [float('inf')] * n
        d[src] = 0
        que = collections.deque([src])
        for step in range(K+1):
            d2 = d.copy()
            for _ in range(len(que)):
                p = que.popleft()
                for q, w in vs[p]:
                    if d[p] + w < d2[q]:
                        d2[q] = d[p] + w
                        que.append(q)
            d = d2
        return d[dst] if d[dst] < float('inf') else -1