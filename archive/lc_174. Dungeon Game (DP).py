class Solution:
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        from sys import maxsize
        if not dungeon: return 0
        m, n = len(dungeon), len(dungeon[0])
        hp = [[maxsize] * (n + 1) for _ in range(m + 1)]
        hp[-1][-2] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                hp[i][j] = max(1, min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j])
        return hp[0][0]