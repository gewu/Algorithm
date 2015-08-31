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
    void Mirror(TreeNode *pRoot){
        if (pRoot == NULL)
            return ;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    void output(TreeNode* pRoot){
        if (pRoot == NULL)
            return ;
        cout << pRoot->val << endl;
        output(pRoot->left);
        output(pRoot->right);
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;

    Solution s;
    s.Mirror(&t1);
    s.output(&t1);
}   
