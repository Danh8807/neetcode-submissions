# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.res = 0
        max_val = root.val
        self.dfs(root, max_val)
        return self.res
    def dfs(self, root, max_val):
        if not root:
            return 0
        max_val = max(max_val, root.val)
        if root.val >= max_val:
            self.res+=1
        self.dfs(root.left, max_val)
        self.dfs(root.right, max_val)
        return 0