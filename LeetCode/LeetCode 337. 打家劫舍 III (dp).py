# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        def dfs(root):
            if root is None:
                return [0, 0]
            l = dfs(root.left)
            r = dfs(root.right)
            sel = root.val + l[1] + r[1]
            not_sel = max(l[0], l[1]) + max(r[0], r[1])
            return [sel, not_sel]
    
        ans = dfs(root)
        return max(ans[0], ans[1])