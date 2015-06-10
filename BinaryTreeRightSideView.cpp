/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreeRightSideView.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/09 21:19:17
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> ret;
        if (root == NULL)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *p = root;
        while (!q.empty()){
            p = q.front();
            q.pop();
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
            if (q.front() == NULL){
                ret.push_back(p->val);
                q.pop();
                if (q.size() != 0)
                    q.push(NULL);
            }
        }
        return ret;
    }

};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;

    Solution s;
    vector<int> ret = s.rightSideView(&t1);
    cout << ret.size() << endl;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
