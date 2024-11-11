# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        treelist = []
        ans = []

        while(len(treelist)!=0 or root != None):
            if(root!=None):
                ans.append(root.val)
                treelist.append(root.right)
                root = root.left
            else:
                root = treelist.pop()
        return ans