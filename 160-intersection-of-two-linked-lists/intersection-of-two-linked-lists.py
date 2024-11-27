# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:

    def findIntersectionNode(self, root):

        node1 = root
        node2 = root

        while(node2!=None and node2.next !=None):
            node1 = node1.next
            node2 = node2.next.next
            if node1 == node2:
                if node1 == None:
                    return None
                break

        while(root!=node1 and node1!=None):
            root = root.next
            node1 = node1.next
        
        return node1


    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        endA = headA

        while(endA.next!=None):
            endA = endA.next

        endA.next = headB

        ans = self.findIntersectionNode(headA)
        endA.next = None
        
        return ans