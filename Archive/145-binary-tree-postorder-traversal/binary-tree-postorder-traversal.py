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
                if(root.right!=None):
                    treelist.append(root.right)
                treelist.append(root)
                root = root.left
            else:
                root = treelist.pop()
                if(len(treelist)!=0 and root.right==treelist[-1]):
                    temp = treelist.pop()
                    treelist.append(root)
                    root = temp
                else:
                    ans.append(root.val)
                    root = None
    
        return ans
