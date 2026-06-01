# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = []
        res =[]
        if root:
            q.append(root)
        while q: 
            size = len(q)
            for i in range(len(q)):
                node = q[0]
                if i == size - 1:
                    res.append(node.val)
                q.pop(0)
                if node.left: 
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return res;  
        