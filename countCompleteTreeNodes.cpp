#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int countNodes(TreeNode* root){
        if (root == NULL)
            return 0;
        int hl = 0;
        int hr = 0;
        TreeNode *l = root;
        TreeNode *r = root;
        while (l) {++hl; l = l->left;}
        while (r) {++hr; r = r->right;}
        if (hl == hr){
            return pow(2, hl) - 1;
        }
        return 1 + countNodes(root->left)+countNodes(root->right);
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;

    Solution s;
    cout << s.countNodes(&t1) << endl;
}
