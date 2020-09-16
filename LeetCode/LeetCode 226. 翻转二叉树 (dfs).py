# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        ans = TreeNode(root.val)

        def dfs(ans: TreeNode, root: TreeNode):
            if not root:
                return 
            if root.left:
                ans.right = TreeNode(root.left.val)
                dfs(ans.right, root.left)
            if root.right:
                ans.left = TreeNode(root.right.val)
                dfs(ans.left, root.right)
            return 
        
        dfs(ans, root)
        return ans