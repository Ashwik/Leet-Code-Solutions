# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def level_order(self, root1, root2):
        if(root1==None and root2==None):
            return True
        elif(root1 == None or root2 == None):
            return False
        
        if(root1.val != root2.val):
            return False

        res1 = self.level_order(root1.left, root2.right)
        res2 = self.level_order(root1.right,root2.left)

        return res1 and res2


    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """

        return self.level_order(root.left,root.right)
        