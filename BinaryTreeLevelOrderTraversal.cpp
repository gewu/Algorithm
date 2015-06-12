/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreeLevelOrderTraversal.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/12 09:49:27
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > levelOrder(TreeNode* root){
        vector<vector<int> > ret;
        vector<int> tmpret;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        TreeNode *p = root;
        while (!q.empty()){
            p = q.front();
            q.pop();
            tmpret.push_back(p->val);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
            if (q.front() == NULL){
                q.pop();
                ret.push_back(tmpret);
                tmpret.clear();
                if (!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ret;
    }

};

int main(){
    TreeNode root(1);
    Solution s;
    vector<vector<int> > ret = s.levelOrder(&root);
    cout << ret.size() << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
