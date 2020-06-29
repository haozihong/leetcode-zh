class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        cnt = collections.Counter(nums)
        vs, ns = list(cnt.keys()), list(map(lambda x: x+1, cnt.values()))
        l = len(vs)
        ans = []
        for i in range(functools.reduce(lambda x, y: x*y, ns)):
            tmp = []
            for j in range(l):
                tmp.extend([vs[j]] * (i % ns[j]))
                i //= ns[j]
            ans.append(tmp)
        return ans