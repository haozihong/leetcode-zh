class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        ids = list(range(n))
        sz = [1] * n
        reach = 0
        def connected(p, q):
            return find(p) == find(q)
        def find(p):
            if ids[p] != p: ids[p] = find(ids[p])
            return ids[p]
        def union(p, q):
            idp, idq = find(p), find(q)
            if idp == idq: return
            nonlocal reach
            if sz[idp] < sz[idq]:
                reach -= sz[idq] // k + sz[idp] // k
                ids[idp] = idq
                sz[idq] += sz[idp]
                reach += sz[idq] // k
                # sets.discard(idp)
            else:
                reach -= sz[idp] // k + sz[idq] // k
                ids[idq] = idp
                sz[idp] += sz[idq]
                reach += sz[idp] // k
                # sets.discard(idq)
        def size(p):
            return sz[find(p)]
        enough = set()
        for i, day in sorted(enumerate(bloomDay), key=lambda x: x[1]):
            reach += 1 // k
            if i > 0 and bloomDay[i-1] <= day: union(i, i-1)
            if i + 1 < n and bloomDay[i+1] <= day: union(i, i+1)
            if reach >= m: return day
        return -1