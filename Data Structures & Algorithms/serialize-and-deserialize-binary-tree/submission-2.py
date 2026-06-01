# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        if not root:
            return 'N,'
        s = ""
        s += str(root.val) 
        s += ','

        s += self.serialize(root.left)
        s += self.serialize(root.right)

        return s
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]: 
        self.i = 0;
        def dfs(data):
            if data[self.i] == 'N':
                self.i+=2
                return None
            s = ""
            while self.i < len(data) and data[self.i] != ',':
                s += data[self.i]
                self.i += 1
            self.i += 1;
            if not s:
                return None
            root = TreeNode(int(s)) 
            root.left = dfs(data)
            root.right = dfs(data)

            return root
        return dfs(data)

        
