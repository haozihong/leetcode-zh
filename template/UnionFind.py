class UnionFind: # Disjoint-set
    def __init__(self, n):
        self.pa = list(range(n))
        self.sz, self.count = [1] * n, n

    def find(self, p):
        if self.pa[p] != p: self.pa[p] = self.find(self.pa[p])
        return self.pa[p]
    
    def union(self, p, q):
        pi, qi = self.find(p), self.find(q)
        if pi == qi: return
        if self.sz[pi] < self.sz[qi]: pi, qi = qi, pi
        self.pa[qi] = pi
        self.sz[pi] += self.sz[qi]
        self.count -= 1
        
    def compare(self, p, q):
        return self.find(p) == self.find(q)


# 每次必向右合并。用于跳过一段范围
# 2612. Minimum Reverse Operations
class UnionFindRight:
    def __init__(self, n):
        self.pa = list(range(n))

    def find(self, p):
        if self.pa[p] != p: self.pa[p] = self.find(self.pa[p])
        return self.pa[p]
    
    def union(self, p, q):
        pi, qi = self.find(p), self.find(q)
        if pi == qi: return
        if pi < qi: pi, qi = qi, pi
        self.pa[qi] = pi
        
    def compare(self, p, q):
        return self.find(p) == self.find(q)


class ParityUnionFind:
    """
    带奇偶/异或关系的并查集。

    用来维护约束：value[u] ^ value[v] = w。
    xr[x] 表示 x 到父节点的异或值；find(x) 后，xr[x] 表示 x 到根的异或值。
    因而当 u、v 连通时，xr[u] ^ xr[v] 就是 u 和 v 之间的异或关系。
    
    3887. Incremental Even-Weighted Cycle Queries
    """
    def __init__(self, n):
        self.pa = list(range(n))
        self.sz, self.count = [1] * n, n
        self.xr = [0] * n   # xr[x] = xor from x to pa[x]

    def find(self, p):
        if self.pa[p] != p:
            parent = self.pa[p]
            self.pa[p] = self.find(parent)
            self.xr[p] ^= self.xr[parent]   # update xor from p to root
        return self.pa[p]
    
    def union(self, p, q, w):
        """
        Try to add constraint: value[p] ^ value[q] = w
        Return True if successful, False if contradiction.
        """
        pi, qi = self.find(p), self.find(q)

        # After find:
        # xr[p] = xor from p to pi
        # xr[q] = xor from q to qi

        if pi == qi:
            return (self.xr[p] ^ self.xr[q]) == w

        # Want to merge qi into pi (or vice versa)
        # Need to set xor between roots correctly.
        # If pa[qi] = pi, then:
        # xr[qi] should be value[qi] ^ value[pi]
        # From:
        # value[p] ^ value[q] = w
        # (value[p]^value[pi]) ^ (value[q]^value[qi]) ^ (value[qi]^value[pi]) = w
        # xr[p] ^ xr[q] ^ xr[qi] = w
        # so xr[qi] = xr[p] ^ xr[q] ^ w

        if self.sz[pi] < self.sz[qi]:
            pi, qi = qi, pi
            p, q = q, p

        self.pa[qi] = pi
        self.xr[qi] = self.xr[p] ^ self.xr[q] ^ w
        self.sz[pi] += self.sz[qi]
        self.count -= 1
        return True
        
    def compare(self, p, q):
        return self.find(p) == self.find(q)


class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        se = sorted(enumerate(edges), key=lambda x: x[1][2])
        def kruskal(pre_add, ban):
            uf, totw = UnionFind(n), 0
            if pre_add >= 0:
                _, (u, v, w) = se[pre_add]
                uf.union(u, v)
                totw += w
                if uf.count == 1: return totw
            for i in range(len(edges)):
                if i == ban or i == pre_add: continue
                _, (u, v, w) = se[i]
                if not uf.compare(u, v):
                    uf.union(u, v)
                    totw += w
                    if uf.count == 1: break
            return totw if uf.count == 1 else 1000*1001
        MSTw = kruskal(-1, -1)
        ans = [[],[]]
        for i in range(len(edges)):
            curw = kruskal(-1, i)
            if curw > MSTw:
                ans[0].append(se[i][0])
            else:
                curw = kruskal(i, -1)
                if curw == MSTw: ans[1].append(se[i][0])
        return ans