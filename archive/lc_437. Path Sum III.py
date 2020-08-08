# Tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if root is None: return 0
        cnt = collections.Counter()
        cnt[0] = 1
        def dfs(node):
            nonlocal s, cnt, ans
            s += node.val
            ans += cnt[s-sum]
            cnt[s] += 1
            if node.left: dfs(node.left)
            if node.right: dfs(node.right)
            cnt[s] -= 1
            s -= node.val
        s, ans = 0, 0
        dfs(root)
        return ans