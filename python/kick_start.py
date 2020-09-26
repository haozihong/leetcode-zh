import math, itertools, collections, functools, bisect, heapq, random
# from sys import setrecursionlimit as srl
# srl(10**5)

inpi = lambda: int(input())
inpm = lambda: map(int, input().split())

sqs = [0, 1, 4, 9]

def fill_sq(n):
    while sqs[-1] < n:
        sqs.append(len(sqs) ** 2)

def solve():
    # N, K = inpm()
    N = inpi()
    A = inpm() #[inpm() for _ in range(N)]
    d = collections.defaultdict(int)
    d[0] = 1
    s, mn, ans = 0, 0, 0
    for x in A:
        s += x
        fill_sq(s - mn)
        mn = min(mn, s)
        for sq in sqs:
            if sq > s - mn: break
            ans += d[s-sq]
        # print(x, ans)
        d[s] += 1
    return ans


T = inpi()
for tc in range(1, T + 1):
    ans = solve()
    print("Case #{}: {}".format(tc, ans))