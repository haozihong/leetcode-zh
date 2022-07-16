'''
牛客网 华为机试 HJ28 素数伴侣
'''

def is_prime(x):
    if x % 2 == 0: return False
    for i in range(3, int(x**.5)+1, 2):
        if x % i == 0: return False
    return True

def augment_path(g, m, n):
    pa, pb = [-1] * m, [-1] * n
    vis = [-1] * m
    ts = -1  # timestamp
    def dfs(u):
        vis[u] = ts
        for v in g[u]:
            if pb[v] == -1 or vis[pb[v]] != ts and dfs(pb[v]):
                pb[v], pa[u] = u, v
                return True
        return False
    for i in range(m):
        ts += 1
        if pa[i] == -1: dfs(i)
    return sum(p != -1 for p in pa)

def solve(vals):
    A, B = [],[]
    for x in vals:
        if x % 2 == 0: A.append(x)
        else: B.append(x)
    G = [[] for _ in A]
    for i, x in enumerate(A):
        for j, y in enumerate(B):
            if is_prime(x + y):
                G[i].append(j)
    return augment_path(G, len(A), len(B))

input()
vals = list(map(int, input().split()))
print(solve(vals))