# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        
        def treetraversal(root):
            if root == None:
                return 0
            
            left = 1 + treetraversal(root.left)
            right = 1 + treetraversal(root.right)

            return max(left,right)
        
        return treetraversal(root)

