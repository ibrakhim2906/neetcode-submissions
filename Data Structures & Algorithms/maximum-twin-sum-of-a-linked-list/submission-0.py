# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow1 = head
        fast1 = head

        while fast1 and fast1.next:
            slow1=slow1.next
            fast1=fast1.next.next
        
        prev = None
        newHead = slow1

        while newHead:
            temp = newHead.next
            newHead.next = prev
            prev = newHead
            newHead = temp
        
        slow2 = head
        slow2_1 = prev

        maxSum = 0

        while slow2_1:
            maxSum = max(maxSum, slow2.val + slow2_1.val)

            slow2 = slow2.next
            slow2_1 = slow2_1.next
        
        return maxSum

        