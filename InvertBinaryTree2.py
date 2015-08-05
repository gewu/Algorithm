class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root):
        if root == None:
            return None
        tmp = root.left
        root.left = root.right
        root.right = tmp

        if root.left != None:
            root.left = self.invertTree(root.left)
        if root.right != None:
            root.right = self.invertTree(root.right)
        
        return root

if __name__ == "__main__":
    r1 = TreeNode(1)
    r2 = TreeNode(2)
    r3 = TreeNode(3)
    r1.left = r2
    r1.right = r3

    s = Solution()
    s.invertTree(r1)
    print r1.left.val
            
