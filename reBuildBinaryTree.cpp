#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    struct TreeNode* rebuildBinary(vector<int>& pre, vector<int> in){
        if (pre.size() == 0 || in.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(pre[0]);
        int k = 0;
        for (; k < in.size(); k++){
            if (pre[0] == in[k])
                break;
        }

        vector<int>::iterator p = pre.begin();
        vector<int>::iterator i = in.begin();

        vector<int> leftin(i, i+k);
        vector<int> leftpre(p+1, p+k+1);

        vector<int> rightin(i+k+1, in.end());
        vector<int> rightpre(p+k+1, pre.end());

        root->left = rebuildBinary(leftpre, leftin);
        root->right = rebuildBinary(rightpre, rightin);
        return root;
    }

    void preOrder(TreeNode* root){
        if (root == NULL)
            return ;
        cout << root->val << endl;
        if (root->left != NULL)
            preOrder(root->left);
        if (root->right != NULL)
            preOrder(root->right);
    }
};

int main(){
    int A[] = {1,2,4,7,3,5,6,8};
    int B[] = {4,7,2,1,5,3,8,6};
    vector<int> numPre(&A[0], &A[8]);
    vector<int> numIn(&B[0], &B[8]);

    Solution s;
    TreeNode *root = s.rebuildBinary(numPre, numIn);
    s.preOrder(root);
}

