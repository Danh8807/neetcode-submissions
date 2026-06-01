# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        first = head
        second = head
        for i in range(n):
            second = second.next;
        if not second: 
            tmp = head
            head = head.next
            del tmp
            return head
        second = second.next
        while second: 
            first = first.next
            second = second.next
        tmp = first.next.next
        first.next = tmp
        return head