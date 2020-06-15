import math, itertools, collections, functools, bisect, heapq, random

from leet_binary_tree import *
from leet_linked_list import *
from leet_tools import *
import leet_ins

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or root.val == val: return root
        return self.searchBST(root.left, val) or self.searchBST(root.right, val)

def main():
    # in0 = [7,[-1,0,0,1,1,2,2]]
    # in1 = [[3,1],[5,2],[6,3]]
    # ins = []
    ou = Solution().shortestSubarray(*leet_ins.ins)
    print(ou)

    # timeit(Solution().distributeCoins)
    # timeit(Solution().distributeCoins2)

if __name__ == "__main__":
    main()
