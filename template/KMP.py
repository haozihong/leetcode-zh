# LC 28. Find the Index of the First Occurrence in a String

class Solution:
    def strStr(self, t: str, s: str) -> int:
        # KMP 1: compute pi[] of s, then search t
        pi = [0] * len(s)
        for i in range(1, len(s)):
            j = pi[i-1]
            while j > 0 and s[i] != s[j]:
                j = pi[j-1]
            pi[i] = j + (s[i] == s[j])
        j = 0
        for i, c in enumerate(t):
            while j > 0 and s[j] != c:
                j = pi[j-1]
            j += s[j] == c
            if j == len(s): return i - j + 1
        return -1

class Solution:
    def strStr(self, t: str, s: str) -> int:
        # KMP 2: compute prefix array of s + "#" + t
        def prefix_fn(s):
            pi = [0] * len(s)
            for i in range(1, len(s)):
                j = pi[i-1]
                while j > 0 and s[i] != s[j]:
                    j = pi[j-1]
                pi[i] = j + (s[i] == s[j])
            return pi
        lps = prefix_fn(s + '#' + t)
        for i in range(2 * len(s), len(s) + 1 + len(t)):
            if lps[i] >= len(s): return i - 2 * len(s)
        return -1

class Solution:
    def strStr(self, t: str, s: str) -> int:
        # Z Algorithm
        def z_fn(s):
            z = [0] * len(s)
            l, r = 0, 0
            for i in range(1, len(s)):
                if i <= r and z[i-l] < r - i + 1:
                    z[i] = z[i-l]
                else:
                    z[i] = max(0, r - i + 1)
                    while i + z[i] < len(s) and s[z[i]] == s[i+z[i]]:
                        z[i] += 1
                if i + z[i] - 1 > r:
                    l, r = i, i + z[i] - 1
            return z
        z = z_fn(s + '#' + t)
        for i in range(len(s) + 1, len(t) + 2):
            if z[i] >= len(s): return i - len(s) - 1
        return -1
