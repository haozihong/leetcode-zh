# Linked List Tree Depth-First Search Breadth-First Search Binary Tree KMP

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        # KMP
        dh = ListNode(None, head)  # dummy head
        dh.pi = None
        head.pi = dh  # points to the last of the longest matching
        def h(q, val):
            while q.pi is not None and q.next.val != val: q = q.pi
            if q.next.val == val: q = q.next
            return q
        q, p = dh, head  # q: previous match
        while p := p.next:
            p.pi = q = h(q, p.val)

        def search(lp, tp): # lp: previous match
            if tp is None: return False
            lp = h(lp, tp.val)
            if lp.next is None: return True
            return search(lp, tp.left) or search(lp, tp.right)
        return search(dh, root)
