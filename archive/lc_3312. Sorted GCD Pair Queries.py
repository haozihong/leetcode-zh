# 容斥原理
# https://oi-wiki.org/math/combinatorics/inclusion-exclusion-principle/

class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        m = max(nums)
        cnt = Counter(nums)
        for i in range(1, m+1):
            for j in range(i * 2, m + 1, i):
                cnt[i] += cnt[j]
        for k in cnt:
            cnt[k] = comb(cnt[k], 2)
        for i in range(m, 0, -1):
            for j in range(i * 2, m + 1, i):
                cnt[i] -= cnt[j]

        res = [0] * len(queries)
        Qs = sorted(enumerate(queries), key=lambda x: x[1], reverse=1)
        s = 0
        for p, c in sorted((+cnt).items()):
            s += c
            while Qs and Qs[-1][1] < s:
                res[Qs.pop()[0]] = p
            if not Qs: break
        return res