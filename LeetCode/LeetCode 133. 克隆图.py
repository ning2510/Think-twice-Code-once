"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        
        vis = {}
        ss = deque([node])
        vis[node] = Node(node.val, [])
        
        while ss:
            k = ss.popleft()
            for x in k.neighbors:
                if x not in vis:
                    vis[x] = Node(x.val, [])
                    ss.append(x)
                vis[k].neighbors.append(vis[x])

        return vis[node]