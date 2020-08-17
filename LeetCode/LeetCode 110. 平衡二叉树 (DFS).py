# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        def dfs(root: TreeNode) -> int:
            if root is None:
                return 0
            return max(dfs(root.left), dfs(root.right)) + 1
        
        if root is None:
            return True
        return abs(dfs(root.left) - dfs(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)