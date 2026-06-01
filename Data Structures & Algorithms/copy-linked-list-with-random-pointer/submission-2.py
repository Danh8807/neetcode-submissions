"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        arr = {}
        arr[None] = None
        cur = head 

        while cur: 
            copy = Node(cur.val)
            arr[cur] = copy
            cur = cur.next
        
        cur = head
        while cur: 
            arr[cur].next = arr[cur.next]
            arr[cur].random = arr[cur.random]
            cur = cur.next
        return arr[head]





