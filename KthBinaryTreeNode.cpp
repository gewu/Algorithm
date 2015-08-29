#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k){
        if (k == 0 || pRoot == NULL)
            return NULL;
        stack<TreeNode*> sta;
        vector<TreeNode*> ret;

        TreeNode* p = pRoot;
        while(!sta.empty() || p != NULL){
            if (p != NULL){
                sta.push(p);
                p = p->left;
            }else {
                p = sta.top();
                sta.pop();
                ret.push_back(p);
                p = p->right;
            }
        }
        if (ret.size() > k)
            return (ret[ret.size()-k]);
        else 
            return ret.back();
    }
};

int main(){

    TreeNode t1(8);
    TreeNode t2(6);
    TreeNode t3(10);
    TreeNode t4(5);
    TreeNode t5(7);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;

    Solution s;
    //s.KthNode(&t1, 1);
    cout << s.KthNode(&t5, 2)->val << endl;
}
