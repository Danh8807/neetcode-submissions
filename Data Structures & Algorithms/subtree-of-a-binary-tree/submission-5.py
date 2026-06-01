# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and subRoot:
            return False
        elif not root and not subRoot:
            return True
        elif self.isSameTree(root, subRoot):
            return True
        else: 
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and q: 
            return False
        elif p and not q: 
            return False
        elif not p and not q:
            return True
        elif p.val != q.val: 
            return False
        else:
            return self.isSameTree(p.left,q.left) and self.isSameTree(p.right, q.right)
   