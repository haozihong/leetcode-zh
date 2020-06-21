class UnionFind:
    def __init__(self, n):
        self.id = list(range(n))
        self.sz, self.count = [1] * n, n

    def find(self, p):
        if self.id[p] != p: self.id[p] = self.find(self.id[p])
        return self.id[p]
    
    def union(self, p, q):
        i, j = self.find(p), self.find(q)
        if i == j: return
        if self.sz[i] < self.sz[j]:
            self.id[i] = j; self.sz[j] += self.sz[i]
        else:
            self.id[j] = i; self.sz[i] += self.sz[j]
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