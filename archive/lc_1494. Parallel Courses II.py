class Solution:
    def minNumberOfSemesters(self, n: int, P: List[List[int]], k: int) -> int:
        eout, ein, degin, degout, depth = [[] for _ in range(n)], [[] for _ in range(n)], [0] * n, [0] * n, [0] * n
        for x, y in P:
            x, y = x-1, y-1
            eout[x].append(y)
            ein[y].append(x)
            degin[y] += 1
            degout[x] += 1
        que = collections.deque(filter(lambda i: degin[i]==0, range(n)))
        deep = 0
        while que:
            for _ in range(len(que)):
                x = que.popleft()
                depth[x] = deep
                for y in eout[x]:
                    degin[y] -= 1
                    if degin[y] == 0: que.append(y)
            deep += 1
        hp = [(-depth[i], i) for i in filter(lambda i: degout[i]==0, range(n))]
        heapq.heapify(hp)
        step = 0
        while hp:
            step += 1
            nxt = []
            for _ in range(k):
                _, y = heapq.heappop(hp)
                for x in ein[y]:
                    degout[x] -= 1
                    if degout[x] == 0: nxt.append((-depth[x], x))
                if not hp: break
            for item in nxt: heapq.heappush(hp, item)
        return step