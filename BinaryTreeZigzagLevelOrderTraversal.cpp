#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > zigagLevelOrder(TreeNode* root){
        queue<TreeNode* > que;
        int flag = 1;
        vector<vector<int> > ret;
        vector<int> tmp;
        que.push(root);
        que.push(NULL);
        if (root == NULL)
            return ret;

        TreeNode* p = NULL;
        while (!que.empty()){
            p = que.front();
            que.pop();
            if (p != NULL){
                tmp.push_back(p->val);
                if (p->left != NULL)
                    que.push(p->left);
                if (p->right != NULL)
                    que.push(p->right);
            }else if (p == NULL){
                if(que.size() != 0){
                    que.push(NULL);
                    if (flag % 2 == 0){
                        reverse(tmp.begin(), tmp.end());
                    }
                    ret.push_back(tmp);
                    flag++; 
                    tmp.clear();
                }else {
                    if (flag % 2 == 0)
                        reverse(tmp.begin(), tmp.end());
                    ret.push_back(tmp);
                    break;
                }
            }
        }
        return ret;
    }
};

int main(){
    TreeNode t1(3);
    TreeNode t2(9);
    TreeNode t3(20);
    TreeNode t4(15);
    TreeNode t5(7);

    t1.left = &t2;
    t1.right = &t3;
    t3.left = &t4;
    t3.right = &t5;

    Solution s;
    vector<vector<int> > ret = s.zigagLevelOrder(&t1);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

}

