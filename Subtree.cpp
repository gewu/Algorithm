#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool hasSubTree(TreeNode* root1, TreeNode* root2){
        if (root2 == NULL)
            return false;
        if (isSame(root1, root2)){
            return true;
        }
        if (root1 == NULL)
            return false;

        return hasSubTree(root1->left, root2) || hasSubTree(root1->right, root2);
    }

    bool isSame(TreeNode* root1, TreeNode* root2){
        if (root2 == NULL)
            return true;
        if (root1 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;

        return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;

    TreeNode t6(2);
    TreeNode t7(4);
    TreeNode t8(5);
    t6.left = &t7;
    t6.right = &t8;
    Solution s;
    cout << s.hasSubTree(&t1, &t6) << endl;

}
