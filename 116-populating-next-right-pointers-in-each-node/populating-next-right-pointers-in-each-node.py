"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':

        if root == None:
            return root
        q = Deque()
        q.append(root)
        ans = root

        while q:
            size = len(q)
            temp = Node()
            while(size):
                size -= 1
                root = q.popleft()
                temp.next = root
                temp = temp.next
                if root.left: q.append(root.left)
                if root.right: q.append(root.right)
        
        return ans

        