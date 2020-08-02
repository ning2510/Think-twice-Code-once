# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        now = root
        while now:
            if now.left:
                pre = nex = now.left
                while pre.right:
                    pre = pre.right
                pre.right = now.right
                now.left = None
                now.right = nex
            now = now.right