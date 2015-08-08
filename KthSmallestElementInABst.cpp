#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode* > s;
        vector<int> value;
        TreeNode* p = root;
        while (!s.empty() || p != NULL){
            if (p != NULL){
                s.push(p);
                p = p->left;
            }else {
                p = s.top();
                s.pop();
                value.push_back(p->val);
                p = p->right;
            }
        }

        return value[k-1];
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t3.left = &t2;
    t3.right = &t4;
    t2.left = &t1;
    t4.right = &t5;

    Solution s;
    cout << s.kthSmallest(&t3, 2) << endl;
}
