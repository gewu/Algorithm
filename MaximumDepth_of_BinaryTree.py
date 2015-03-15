class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root):
        if root == None:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
if __name__ == "__main__":
	a = TreeNode(1)
	b = TreeNode(2);
	c = TreeNode(3);
	a.left = b
	a.rigth = c
	d = Solution();
	print d.maxDepth(a)
