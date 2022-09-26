class UnionFind:
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