# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        ans = 100000

        def dfs(deep: int, root: TreeNode):
            nonlocal ans
            if not root.left and not root.right:
                ans = min(ans, deep)
            
            if root.left:
                dfs(deep + 1, root.left)
            
            if root.right:
                dfs(deep + 1, root.right)
        
        dfs(1, root)
        return ans