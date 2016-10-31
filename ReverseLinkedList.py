# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        vals = []
        it = head
        while(it is not None):
            vals.append(it.val)
            it = it.next
            
        i = len(vals) - 1
        it = head
        while(it is not None):
            it.val = vals[i]
            i-=1
            it = it.next
        return head
        