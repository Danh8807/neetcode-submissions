# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = -1001;
        def dfs(root):
            if not root:
                return 0;
            
            max_left = dfs(root.left);
            max_right = dfs(root.right);

            max_left = max(max_left, 0);
            max_right = max(max_right, 0);

            self.res = max(self.res, root.val + max_left + max_right); 

            return root.val + max(max_left, max_right);
        dfs(root);
        return self.res;
