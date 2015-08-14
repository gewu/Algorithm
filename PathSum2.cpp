#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber){
       vector<int> tmp;
       vector<vector<int> > ret;
       helpFindPath(root, expectNumber, tmp, ret);
       return ret;
    }

    void helpFindPath(TreeNode* root, int target,  vector<int>& tmp, vector<vector<int> >& ret){
        tmp.push_back(root->val);
        int cur = target - root->val;
        if (cur == 0 && root->left == NULL && root->right == NULL){
            ret.push_back(tmp);
        }

        if (root->left != NULL){
            helpFindPath(root->left, cur, tmp, ret);
            tmp.pop_back();
        }

        if (root->right != NULL){
            helpFindPath(root->right, cur, tmp, ret);
            tmp.pop_back();
        }

    }
};

int main(){
    TreeNode t1(10);
    TreeNode t2(5);
    TreeNode t3(12);
    TreeNode t4(4);
    TreeNode t5(7);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    Solution s;
    vector<vector<int> > ret = s.FindPath(&t1, 22);
    for (int i = 0; i < ret[1].size(); i++){
        cout << ret[1][i] << " ";
    }
}

