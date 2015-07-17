/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FlattenBinaryTreeToLinkedList.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/17 14:58:43
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    void flatten(TreeNode *root){
        if (root == NULL)
            return ;
        if (root->left != NULL){
            TreeNode* rightNode = root->right;
            TreeNode* leftNode = root->left;
            root->left = NULL;
            root->right = leftNode;
            TreeNode* p = leftNode;
            while (p->right != NULL){
                p = p->right;
            }
            p->right = rightNode;
        }
        flatten(root->right);
    }
};

int main(){
    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    r1.left = &r2;
    r1.right = &r3;

    Solution s;
    s.flatten(&r1);
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
