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

        main_node = head
        
        while(main_node!=None):
            copy_node = Node(main_node.val)
            next_main_node = main_node.next
            main_node.next = copy_node
            copy_node.next = next_main_node
            main_node = next_main_node

        
        main_node = head

        while(main_node!=None):
            copy_node = main_node.next
            if main_node.random != None:
                copy_node.random = main_node.random.next
            main_node = copy_node.next


        copy_node = head.next
        ans = copy_node

        while(copy_node.next!=None):
            copy_node.next = copy_node.next.next
            copy_node = copy_node.next
        
        return ans

        






        