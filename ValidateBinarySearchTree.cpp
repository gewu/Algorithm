#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool isValidBST(TreeNode* root){
        if (root == NULL)
            return true;

        stack<TreeNode *> s;
        TreeNode* q = root;
        while (q->left != NULL){
            q = q->left ; 
        }
        int pre = q->val;
        int flag = 0;
        TreeNode* p = root;

        while (!s.empty() || p != NULL){
            if (p != NULL){
                s.push(p);
                p = p->left;
            }else {
                p = s.top();
                s.pop();
                cout << p->val << " " ;
                if ( p->val <= pre && flag != 0){
                    return false;
                }
                flag = 1;
                pre = p->val;
                p = p->right; 
            }
        }
        return true;
    }
};


int main(){
    TreeNode t1(1);
    TreeNode t2(5);


    t1.right = &t2;

    Solution s;
    cout << s.isValidBST(&t1) << endl;
}
