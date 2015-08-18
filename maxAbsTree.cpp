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
    vector<int> maxAbs(TreeNode* root){

        int max = root->val;
        int min = root->val;
        vector<int> ret;

        TreeNode* p = NULL;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()){
            p = s.top();
            s.pop();
            if (p->val > max){
                max = p->val;
            }else if (p->val < min){
                min = p->val;
            }
            if (p->right != NULL)
                s.push(p->right);
            if (p->left != NULL)
                s.push(p->left);
        }
        ret.push_back(max);
        ret.push_back(min);
        return ret;
    }
};

int main(){
    TreeNode t1(4);
    TreeNode t2(1);
    TreeNode t3(3);
    TreeNode t4(2);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;

    Solution s;
    vector<int> ret = s.maxAbs(&t1);
    for (int i = 0; i < ret.size(); i++){
        cout << ret[i] << " " ;
    }
    cout << endl;
}


