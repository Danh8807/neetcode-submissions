# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None: 
        slow = head
        fast = head
        while fast and fast.next: 
            slow = slow.next
            fast = fast.next.next 

        prev = None
        cur = slow.next
        slow.next = None
        while cur: 
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        temp1 = head
        temp2 = prev

        while temp1 and temp2:
            tmp1, tmp2 = temp1.next, temp2.next
            temp1.next = temp2
            temp2.next = tmp1
            temp1 = tmp1
            temp2 = tmp2
       