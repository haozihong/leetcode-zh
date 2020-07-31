class Solution:
    def lastSubstring(self, s: str) -> str:
        l = len(s)
        mxc = max(s)
        d, i, mxl = {}, 0, 0
        while i < l:
            if s[i] == mxc:
                j = i + 1
                while j < l and s[j] == mxc: j += 1
                d[i] = j
                mxl = max(mxl, j - i)
                i = j + 1
            else:
                i += 1
        for i in list(d):
            if d[i] - i < mxl: del d[i]
        while len(d) > 1:
            mxc = max(s[d[i]] for i in d if d[i] < l)
            for i in list(d):
                if d[i] < l and s[d[i]] == mxc:
                    d[i] += 1
                else:
                    del d[i]
        i = list(d)[0]
        return s[i:]