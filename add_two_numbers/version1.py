# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 and not l2:
            return None
        carry =0;
        head =l1 
        last = None
        next1 = l1
        next2 = l2
        
        while(next1 and next2):
            temp = next1.val+next2.val+carry
            next1.val = next2.val = temp%10
            carry = temp/10
            last = next1
            next1 = next1.next
            next2 = next2.next
            
        if next1:
            while next1:
                temp = next1.val+carry
                next1.val = temp%10
                carry = temp/10
                last = next1
                next1 = next1.next

        if next2:
            head = l2
            while next2:
                temp = next2.val+carry
                next2.val = temp%10
                carry = temp/10
                last = next2
                next2 = next2.next   
                
        if carry:
            last.next = ListNode(1)
        return head