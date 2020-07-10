# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if root is None: return 0
        que, lv = collections.deque([(root, 0)]), 0
        ans = 0
        while que:
            mn, mx = 1<<lv, -1
            for _ in range(len(que)):
                node, pos = que.popleft()
                mn, mx = min(mn, pos), max(mx, pos)
                if node.left: que.append((node.left, pos * 2))
                if node.right: que.append((node.right, pos * 2 + 1))
            ans = max(ans, mx - mn + 1)
            lv += 1
        return ans