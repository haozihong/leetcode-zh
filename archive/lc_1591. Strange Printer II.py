# Greedy, Topology Sort, Graph

class Solution:
    def isPrintable(self, A: List[List[int]]) -> bool:
        m, n = len(A), len(A[0])
        bounds = {}
        for i in range(m):
            for j in range(n):
                t = A[i][j]
                if t not in bounds:
                    bounds[t] = (i, j, i, j)
                else:
                    x1, y1, x2, y2 = bounds[t]
                    bounds[t] = (min(x1, i), min(y1, j), max(x2, i), max(y2, j))
        clr_num = len(bounds)
        tb = collections.defaultdict(set)
        din = collections.Counter()
        for clr in bounds:
            x1, y1, x2, y2 = bounds[clr]
            for i in range(x1, x2+1):
                for j in range(y1, y2+1):
                    if A[i][j] != clr and clr not in tb[A[i][j]]:
                        din[clr] += 1
                        tb[A[i][j]].add(clr)
                        
        que = list(filter(lambda clr: din[clr] == 0, bounds))
        done = len(que)
        while que:
            p = que.pop()
            for q in tb[p]:
                din[q] -= 1
                if din[q] == 0:
                    que.append(q)
                    done += 1
        return done == clr_num