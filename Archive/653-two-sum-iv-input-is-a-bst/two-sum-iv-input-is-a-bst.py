# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        
        def inOrder(root):
            if root:
                yield from inOrder(root.left)
                yield root.val
                yield from inOrder(root.right)

        def inOrderReversed(root):
            if root:
                yield from inOrderReversed(root.right)
                yield root.val
                yield from inOrderReversed(root.left)

        leftGenerator = inOrder(root)
        rightGenerator = inOrderReversed(root)

        left, right = next(leftGenerator), next(rightGenerator)
        while left < right:
            if left + right == k: return True
            if left + right < k:
                left = next(leftGenerator)
            else:
                right = next(rightGenerator)
        return False
        