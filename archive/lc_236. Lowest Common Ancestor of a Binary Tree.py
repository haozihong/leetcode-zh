# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        pathp, pathq = [], []
        stack = [[root, 0]]
        LCAi = -1
        while stack:
            node, i = stack[-1]
            if node==p or node==q:
                if LCAi == -1:
                    if node==p and node==q: return node
                    LCAi = len(stack) - 1
                    if node==p: p = None
                    else: q = None
                else:
                    return stack[LCAi][0]
            children = (node.left, node.right)
            while i < 2 and children[i] is None: i += 1
            if i < 2:
                stack[-1][1] = i + 1
                stack.append([children[i], 0])
            else:
                stack.pop()
                LCAi = min(LCAi, len(stack) - 1)
        return None