# 2172. Maximum AND Sum of Array

class Hungarian:  # KM
    def __init__(self, n):
        self.n = n
        self.pa, self.pb = [-1] * n, [-1] * n
        self.g = defaultdict(lambda: defaultdict(int))
    
    def add_edge(self, u, v, w):
        self.g[u][v] = w
    
    def solve(self):
        n, g, pa, pb = self.n, self.g, self.pa, self.pb
        la, lb = [max(g[i].values(), default=0) for i in range(n)], [0] * n
        def bfs(p):
            def check(v):
                visb[v] = True
                if pb[v] == -1:
                    while v != -1:
                        pa[pre[v]], pb[v], v = v, pre[v], pa[pre[v]]
                    return True
                else:
                    dq.append(pb[v])
                    visa[pb[v]] = True
            visa, visb, pre = [False] * n, [False] * n, [-1] * n
            slack = [float('inf')] * n  # for group b
            dq = deque([p])
            visa[p] = True
            while True:
                while dq:
                    u = dq.popleft()
                    for v in range(n):
                        if not visb[v]:
                            d = la[u] + lb[v] - g[u][v]
                            if d < slack[v]: slack[v], pre[v] = d, u
                            if slack[v] == 0 and check(v): return
                d = min(slack[v] for v in range(n) if not visb[v])
                for i in range(n):
                    if visa[i]: la[i] -= d
                    if visb[i]:
                        lb[i] += d
                    else:
                        slack[i] -= d
                for v in range(n):
                    if not visb[v] and slack[v] == 0 and check(v): return
            
        for i in range(n):
            if pa[i] == -1: bfs(i)
        return sum(g[i][pa[i]] for i in range(n))

class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        solver = Hungarian(numSlots * 2)
        for i in range(numSlots):
            for j, x in enumerate(nums):
                solver.add_edge(i*2, j, (i+1) & x)
                solver.add_edge(i*2+1, j, (i+1) & x)
        return solver.solve()