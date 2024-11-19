# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        
        def pushleft(st, root):
            while root:
                st.append(root)
                root = root.left
        
        def pushright(st,root):
            while root:
                st.append(root)
                root = root.right
        
        def nextleft(st):
            root = st.pop()
            pushleft(st,root.right)
            return root.val
        
        def nextright(st):
            root = st.pop()
            pushright(st,root.left)
            return root.val
        
        leftstack, rightstack = [],[]

        pushleft(leftstack,root)
        pushright(rightstack,root)

        i,j = nextleft(leftstack),nextright(rightstack)

        while(i<j):
            sum = i + j
            if(sum==k):
                return True
            elif sum<k:
                i = nextleft(leftstack)
            else:
                j = nextright(rightstack)

        return False
        