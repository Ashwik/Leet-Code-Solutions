# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        len = 0
        temp = head
        while(temp!=None):
            temp = temp.next
            len = len+1
        if(n==len):
            return head.next

        start = len-n
        temp = head
        while(start>1):
            temp=temp.next
            start = start-1

        temp.next = temp.next.next
        return head
        