/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LowestCommonAncestorOfABinarySearchTree.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/13 20:26:38
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL)
            return root;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
            
    }
};


int main(){

    TreeNode t1(6);
    TreeNode t2(2);
    TreeNode t3(8);
    TreeNode t4(0);
    TreeNode t5(4);
    TreeNode t6(7);
    TreeNode t7(9);

    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    Solution s;
    cout << (s.lowestCommonAncestor(&t1, &t4, &t5))->val << endl;

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
