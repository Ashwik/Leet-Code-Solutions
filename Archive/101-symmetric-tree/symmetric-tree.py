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
        #return self.level_order(root.left,root.right)
        
        
        q1 = deque()
        q2 = deque()
        q1.append(root.left)
        q2.append(root.right)

        while(q1 and q2):
            size1= len(q1)
            size2 = len(q2)
            if(size1 != size2):
                return False

            while(size1):
                root1 = q1.popleft()
                root2 = q2.popleft()
                if(root1 == None and root2 == None):
                    size1 = size1-1
                    continue
                elif(root1 == None or root2 == None):
                    return False
                
                if(root1.val != root2.val):
                    return False
                
                q1.append(root1.left)
                q1.append(root1.right)
                q2.append(root2.right)
                q2.append(root2.left)
                size1 = size1-1
        
        return True

                
