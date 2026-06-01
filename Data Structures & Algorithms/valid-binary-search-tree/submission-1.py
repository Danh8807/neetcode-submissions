# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root, 1001, -1001)
        
    def dfs( self, root, upperbound, lowerbound):
        if not root: 
            return True
        elif root.val <= lowerbound or root.val >= upperbound:
            return False
        else: 
            return self.dfs(root.left, root.val, lowerbound) and self.dfs(root.right, upperbound, root.val)
