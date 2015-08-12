#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
    void connect(TreeLinkNode *root){
        if (root == NULL)
            return ;
        queue <TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode* p = NULL;
        while (!q.empty()){
            p = q.front();
            q.pop();
            if (p != NULL){
                p->next = q.front();
                if (p->left != NULL){
                    q.push(p->left);
                }
                if (p->right != NULL){
                    q.push(p->right);
                }
            }else {
                if (q.size() == 0)
                    return ;
                q.push(NULL);
            }
        }
    }
};

int main(){
    TreeLinkNode t1(1);
    TreeLinkNode t2(2);
    TreeLinkNode t3(3);
    //TreeLinkNode t4(4);
    t1.left = &t2;
    t1.right = &t3;
    //t3.left = &t4;

    Solution s;
    s.connect(&t1);
    if (t2.next == NULL){
        cout << "YYYYY" << endl;
    }

}
