#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool isBalance(TreeNode* pRoot){
        if (pRoot == NULL)
            return true;
        int r = deep(pRoot->right);
        int l = deep(pRoot->left);
        if (r-l > 1 || r-l < -1){
            return false;
        }
        isBalance(pRoot->left);
        isBalance(pRoot->right);

        
    }

    int deep(TreeNode* pRoot){
        if (pRoot == NULL)
            return 0;
        if (pRoot->left == NULL && pRoot->right == NULL)
            return 1;
        int r = deep(pRoot->right) + 1;
        int l = deep(pRoot->left) + 1;
        return r > l ? r : l;
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;
    t6.right = &t7;
    Solution s;
    cout << s.deep(&t1) << endl;

}
