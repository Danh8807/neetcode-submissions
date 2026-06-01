# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        start = dummy
        tail = dummy 
        for i in range(n+1):
            tail = tail.next
        while tail: 
            tail = tail.next
            start = start.next
        toDelete = start.next
        start.next = start.next.next
        del toDelete
        return dummy.next