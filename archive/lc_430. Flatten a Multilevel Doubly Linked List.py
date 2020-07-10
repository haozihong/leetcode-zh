"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def flatten2(head: 'Node') -> ('Node'):
            prev, p = None, head
            while p:
                if p.child:
                    ch, ct = p.child, flatten2(p.child)
                    p.child = None
                    q = p.next
                    p.next, ch.prev = ch, p
                    ct.next = q
                    if q: q.prev = ct
                    prev, p = ct, q
                else:
                    prev, p = p, p.next
            return prev
        flatten2(head)
        return head