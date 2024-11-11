# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        treelist = []
        ans = []

        while(len(treelist)!=0 or root != None):
            if(root!=None):
                treelist.append(root)
                root = root.left
            else:
                root = treelist.pop()
                if(root.right!=None):
                    root.left = root.right
                    root.right = None
                else:
                    ans.append(root.val)
                    root = None


        return ans
