class SAM:
    class Node:
        def __init__(self):
            self.len, self.fa, self.ch = 0, None, {}
            self.is_end = False
        
    def __init__(self):
        self.las = self.Node()
        self.nodes = [self.las]
    
    def add(self, c, is_end):
        p = self.las
        self.las = np = self.Node()
        np.len = p.len + 1
        np.is_end = is_end
        self.nodes.append(np)
        while p is not None and c not in p.ch:
            p.ch[c] = np
            p = p.fa
        if p is None:
            np.fa = self.nodes[0]  # case 1
        else:
            q = p.ch[c]
            if q.len == p.len + 1:
                np.fa = q  # case 2
                q.is_end = is_end
            else:
                nq = self.Node()
                nq.fa, nq.ch, nq.is_end = q.fa, q.ch.copy(), is_end
                nq.len = p.len + 1
                self.nodes.append(nq)
                q.fa = np.fa = nq
                while p is not None and p.ch[c] == q:
                    p.ch[c] = nq
                    p = p.fa  # case 3
                while p is not None and c in p.ch:
                    p.ch[c].is_end = is_end
                    p = p.fa
        
class Solution:
    def sumScores(self, s: str) -> int:
        res = 0
        sam = SAM()
        for i, c in enumerate(s):
            sam.add(c, i == len(s) - 1)
        p, lcp = sam.nodes[0], 0
        for i, c in enumerate(s):
            p = p.ch[c]
            print(s[:i+1], p.is_end)
            if p.is_end: lcp = i + 1
            res += lcp
        return res