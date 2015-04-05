#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool isSymmetric(TreeNode *root){
        if (root == NULL){
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *r1, TreeNode *r2){
        bool flag = true;
        if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL || r2 == NULL || r1->val != r2->val)
            return false;
        if (r1->val == r2->val)
            flag = isMirror(r1->right, r2->left) && isMirror(r1->left, r2->right);
        return flag;
    }
};

int main(){
    TreeNode node(1);
    Solution solution;
    bool res = solution.isSymmetric(&node);
    cout << res << endl;
}


