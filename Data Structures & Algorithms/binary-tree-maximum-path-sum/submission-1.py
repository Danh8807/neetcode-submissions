# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = -1001
        self.dfs(root)
        return self.res
    def dfs(self, root):
        if not root:
            return 0
        
        maxLeft = self.dfs(root.left)
        maxRight = self.dfs(root.right)
        maxLeft = max(maxLeft,0)
        maxRight = max(maxRight,0)

        self.res = max(self.res, root.val + maxLeft + maxRight)

        return root.val + max(maxLeft, maxRight)