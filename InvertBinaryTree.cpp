/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file InvertBinaryTree.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/18 14:14:57
 * @brief 
 *  
 **/

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* invertTree(TreeNode* root){
        if (root == NULL)
            return NULL;
        
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }

    TreeNode* invertTree2(TreeNode *root){
        if (root == NULL)
            return root;
        stack<TreeNode *> s;
        TreeNode *p = NULL;
        s.push(root);
        while (!s.empty()){
            p = s.top();
            s.pop();
            TreeNode *tmp = p->left;
            p->left = p->right;
            p->right = tmp;
            if (p->right != NULL)
                s.push(p->right);
            if (p->left != NULL)
                s.push(p->left);
        }
        return root;
    }
};

int main(){
    Solution s;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
