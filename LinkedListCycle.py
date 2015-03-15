class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    def hasCycle(self, head):
	pl1 = head
	pl2 = head
	while(pl2 != None and pl2.next != None):
		pl2 = pl2.next.next
		pl1 = pl1.next
		if (pl1 == pl2):
			return True
	return False

if __name__ == "__main__":
    linka = ListNode(1)
    linkb = ListNode(2)
    linkc = ListNode(3)
    linkd = ListNode(4)
    linka.next = linkb
    linkb.next = linkc
    linkc.next = linkd
    linkd.next = linkb
    
    solution = Solution();
    print solution.hasCycle(linka)

