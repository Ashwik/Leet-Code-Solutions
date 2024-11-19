# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:

        nodelist = []

        q = []
        
        while(q or root):
            if root:
                q.append(root)
                root = root.left
            else:
                root = q.pop()
                nodelist.append(root.val)
                root = root.right

        for node in nodelist:
            print("val:", node)

        i,j = 0,len(nodelist)-1

        while(i<j):
            sum = nodelist[i] + nodelist[j]
            if(sum==k):
                return True
            elif sum>k:
                j = j-1
            else:
                i = i+1
        
        return False


        