# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        ans = []
        ss = deque([root])
        flag = True

        while len(ss) > 0:
            n = len(ss)
            now = []
            mm = ss.copy()
            pp = deque()
            for i in range(n):
                k = ss.popleft()
                if k.left:
                    pp.append(k.left)
                if k.right:
                    pp.append(k.right)

            ss = pp.copy()
            pp = mm.copy()

            for i in range(n):
                k = None
                if flag:
                    k = pp.popleft()
                else:
                    k = pp.pop()
                now.append(k.val)

            ans.append(now)
            flag = not flag

        return ans
                