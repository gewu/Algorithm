class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        if head == None or head.next == None:
            return head

        while (head.next != NULL):


