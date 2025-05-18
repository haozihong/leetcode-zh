# Lowest Common Ancestor
# 来自 https://oi-wiki.org/graph/lca/#%E5%AE%9E%E7%8E%B0_1. ChatCPT 翻译成 Python


class LCA:
    def __init__(self, n):
        """
        n: 树的节点数，节点编号假定为 0..n-1
        """
        self.n = n
        self.graph = [[] for _ in range(n)]   # 邻接表
        self.euler = []                       # 存放欧拉序列节点编号
        self.depth = []                       # 与 euler 对应的深度序列
        self.first = [-1] * n                 # first[u] = u 第一次出现在 euler 中的位置
        # 以下在 build() 时构建
        self.log = []     # 预计算 log
        self.st = []      # 稀疏表 st[k][i] 存放区间 [i, i+2^k-1] 最小深度位置在 depth 中的下标

    def add_edge(self, u, v):
        """在无根树（或根树）中加入一条 u–v 边"""
        self.graph[u].append(v)
        self.graph[v].append(u)

    def _dfs(self, u, d, parent):
        """深度优先遍历，记录欧拉序列与深度"""
        self.first[u] = len(self.euler)
        self.euler.append(u)
        self.depth.append(d)
        for v in self.graph[u]:
            if v == parent: continue
            self._dfs(v, d + 1, u)
            # 回溯到 u 时，要在 euler 中再记录一次 u
            self.euler.append(u)
            self.depth.append(d)

    def build(self, root=0):
        """
        1) 从 root 开始跑一次 DFS，填充 self.euler、self.depth、self.first
        2) 构建 RMQ 的稀疏表 self.st
        """
        # 1. 欧拉遍历
        self._dfs(root, 0, -1)
        m = len(self.euler)

        # 2. 预计算 log2
        self.log = [0] * (m + 1)
        for i in range(2, m + 1):
            self.log[i] = self.log[i // 2] + 1

        # 3. 初始化稀疏表
        K = self.log[m] + 1
        self.st = [[0] * m for _ in range(K)]
        # st[0][i] = i，表示区间 [i,i] 最小值位置就是 i 自己
        for i in range(m):
            self.st[0][i] = i

        # 4. 动态构建
        for k in range(1, K):
            length = 1 << (k - 1)
            for i in range(m - (1 << k) + 1):
                left = self.st[k-1][i]
                right = self.st[k-1][i + length]
                # 选深度较小的位置
                if self.depth[left] < self.depth[right]:
                    self.st[k][i] = left
                else:
                    self.st[k][i] = right

    def _rmq(self, l, r):
        """
        在 depth 数组里查询区间 [l, r] 最小值的下标
        返回的是 depth 中下标，而不是节点编号
        """
        j = self.log[r - l + 1]
        left = self.st[j][l]
        right = self.st[j][r - (1 << j) + 1]
        return left if self.depth[left] < self.depth[right] else right

    def query(self, u, v):
        """
        返回节点 u, v 的 LCA（以编号形式）
        """
        l = self.first[u]
        r = self.first[v]
        if l > r:
            l, r = r, l
        idx = self._rmq(l, r)
        return self.euler[idx]


if __name__ == "__main__":
    # 示例用法
    n = 9
    lca = LCA(n)
    edges = [
        (0,1),(0,2),(1,3),(1,4),(2,5),(2,6),(4,7),(4,8)
    ]
    for u,v in edges:
        lca.add_edge(u, v)

    lca.build(root=0)

    # 测试几组查询
    tests = [(3,4), (3,6), (7,8), (5,6), (7,5)]
    for u,v in tests:
        print(f"LCA({u},{v}) = {lca.query(u,v)}")
