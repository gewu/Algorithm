class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def Serialize(self, root):
        ret = []
        if root == None:
            return ret
        
        sta = []
        sta.append(root)
        while (len(sta) > 0):
            p = sta[0]
            sta.pop(0)
            if p != None:
                ret.append(p.val)
                if p.left != None:
                    sta.append(p.left)
                else:
                    sta.append(None)
                if p.right != None:
                    sta.append(p.right)
                else:
                    sta.append(None)
            else:
                ret.append(None)
        return ret
            
            
    def Deserialize(self, tree_str):
        if len(tree_str) == 0:
            return 

        treeNode = []
        for m in tree_str:
            if m == None:
                treeNode.append(None)
            else:
                treeNode.append(TreeNode(m))

        treeNode[0].left = treeNode[1]
        treeNode[0].right = treeNode[2]
        for i in range(1, len(treeNode)):
            if treeNode[i] != None:
                treeNode[i].left = treeNode[2*i+1]
                treeNode[i].right = treeNode[2*i+2]
        
        return treeNode[0]
                



if __name__ == "__main__":
    t1 = TreeNode(8)
    t2 = TreeNode(6)
    t3 = TreeNode(10)
    t4 = TreeNode(5)
    t5 = TreeNode(7)
    t6 = TreeNode(9)
    t7 = TreeNode(11)

    t1.left = t2
    t1.right = t3
    t2.left = t4
    t2.right = t5
    t3.left = t6
    t3.right = t7

    sol = Solution()
    m = sol.Serialize(t1)
    print m

    root = sol.Deserialize(m)
    print root.val
    print root.left.val
    print root.right.val
    print root.left.left.val

