# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        if head==None or head.next == None: return False

        node1 = head
        node2 = head.next.next

        while node1!=node2 and node2!=None and node2.next!=None:
            node1 = node1.next
            node2 = node2.next.next

        if node1 == node2: return True

        return False