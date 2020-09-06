# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans = list()
        if not root:
            return ans
        
        ss = collections.deque([root])
        while ss:
            n = len(ss)
            now = list()
            for i in range(n):
                k = ss.popleft()
                now.append(k.val)
                if k.left:
                    ss.append(k.left)
                if k.right:
                    ss.append(k.right)
            ans.append(now)
        
        return ans[::-1]