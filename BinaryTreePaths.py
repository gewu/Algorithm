class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        if root == None:
            return []
        ret = []
        tmp = ""
        self.help(root, tmp, ret)
        return ret

    def help(self, root, tmp, res):
        if tmp == "":
            tmp = str(root.val)
        else:
            tmp = "%s->%s" % (tmp, root.val)
        if root.left == None and root.right == None:
            res.append(tmp)

        if root.left != None:
            self.help(root.left, tmp, res)
        if root.right != None:
            self.help(root.right, tmp, res)

if __name__ == "__main__":
    s = Solution()
    t1 = TreeNode(1);
    t2 = TreeNode(2);
    t3 = TreeNode(3);
    t4 = TreeNode(4);
    t5 = TreeNode(5);

    t1.left = t2
    t1.right = t3
    t3.left = t4;
    t3.right = t5

    ret = s.binaryTreePaths(t1)
    for _ in ret:
        print _
    

