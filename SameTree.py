class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSameTree(self, p, q):
        if (p == None and q == None):
            return True
        if (p == None or q == None):
            return False
        return (p.val == q.val) and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

if __name__ == "__main__":
	rt1 = TreeNode(1)
	rt2 = TreeNode(1)
	rt3 = TreeNode(1)
	rt4 = TreeNode(1)
	rt1.right = rt2
	rt3.right = rt4
	solution = Solution()
	print solution.isSameTree(rt1, rt3)
