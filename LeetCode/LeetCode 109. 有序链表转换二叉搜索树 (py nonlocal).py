# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        
        def get_len(head: ListNode) -> int:
            ans = 0
            while head:
                ans += 1
                head = head.next
            return ans

        def dfs(l: int, r: int) -> TreeNode:
            if l > r:
                return None
            mid = (l + r + 1) // 2
            node = TreeNode()
            node.left = dfs(l, mid - 1)
            # nonlocal关键字用来在函数或其他作用域中使用外层(非全局)变量
            nonlocal head
            node.val = head.val
            head = head.next
            node.right = dfs(mid + 1, r)
            return node

        len = get_len(head)
        return dfs(0, len - 1)