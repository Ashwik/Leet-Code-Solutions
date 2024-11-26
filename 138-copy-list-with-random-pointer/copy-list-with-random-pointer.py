"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        
        if head == None: return head

        d = {}
        cur = head

        while cur!=None:
            new_node = Node(cur.val)
            d[cur] = new_node
            cur = cur.next
        
        res = d[head]
        cur  = res
        
        while head!=None:
            if head.next!=None:
                cur.next = d[head.next]
            
            if head.random != None:
                cur.random = d[head.random]
            
            head = head.next
            cur = cur.next
        
        return res
        



        