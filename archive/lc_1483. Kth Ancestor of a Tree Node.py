class TreeAncestor:

    def __init__(self, n: int, parent):
        pas = [[pa] for pa in parent]
        for step in itertools.count(1):
            flag = False
            for i in range(1, n):
                d = len(pas[i])
                if d == step and len(pas[pas[i][-1]]) >= d and pas[pas[i][-1]][d-1] != -1:
                    flag = True
                    pas[i].append(pas[pas[i][-1]][d-1])
            if not flag: break
        self.pas = pas

    def getKthAncestor(self, node: int, k: int) -> int:
        while k and node != -1:
            d = min(len(self.pas[node])-1, int(math.log2(k)))
            node = self.pas[node][d]
            k -= 1 << d
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)