# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0
    
        def dfs(root, m):
            if not root:
                return 
            if root.val >= m:
                m = root.val
                self.count +=1;
            dfs(root.right, m)
            dfs(root.left, m)

        dfs(root, root.val)
        return self.count
