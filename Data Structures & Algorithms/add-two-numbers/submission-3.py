# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        head = dummy
        rem = 0
        while l1 or l2:
            num = 0
            if l1 and l2: 
                num = l1.val + l2.val + rem
                l1 = l1.next
                l2 = l2.next
            elif l1: 
                num = l1.val + rem
                l1 = l1.next
            else: 
                num = l2.val + rem
                l2 = l2.next
            tmp = ListNode(num%10)
            if num >= 10:
                rem = num//10
            else: 
                rem = 0
            dummy.next = tmp
            dummy = dummy.next
        if rem > 0: 
            tmp2 = ListNode(rem)
            dummy.next = tmp2
        return head.next