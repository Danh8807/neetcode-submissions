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
        arr = collections.defaultdict(lambda: Node(0))
        arr[None] = None 
        cur = head 

        while cur: 
            arr[cur].val = cur.val
            arr[cur].next = arr[cur.next]
            arr[cur].random = arr[cur.random]
            cur = cur.next
        return arr[head]





