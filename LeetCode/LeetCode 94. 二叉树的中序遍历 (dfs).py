# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = list()

        def dfs(root: TreeNode):
            if not root:
                return
            dfs(root.left)
            ans.append(root.val)
            dfs(root.right)
            return

        dfs(root)
        return ans