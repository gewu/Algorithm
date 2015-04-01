#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode (int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool isBalanced(TreeNode *root){
        if (root == NULL){
            return true;
        }
        int m = depth(root->left)-depth(root->right);
        if (m>1 || m<-1)
            return false;
        else 
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode *root){
        if (root == NULL)
            return 0;
        int dleft = depth(root->left);
        int right = depth(root->right);
        return dleft > dright ? dleft+1:dright+1;
    }

};
