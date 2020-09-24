# from sys import setrecursionlimit as srl
# srl(10**5)

inpi = lambda: int(input())
inpm = lambda: map(int, input().split())


def solve():
    N, K = inpm()
    A = inpm()#[inpm() for _ in xrange(N)]

    return 0


T = inpi()
for tc in range(1, T + 1):
    ans = solve()
    print("Case #{}: {}".format(tc, ans))