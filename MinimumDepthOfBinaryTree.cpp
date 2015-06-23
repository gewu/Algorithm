/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MinimumDepthOfBinaryTree.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/23 21:11:11
 * @brief 
 *  
 **/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int minDepth(TreeNode* root){
        if (root == NULL)
            return 1;
        if (root->left == NULL && root->right == NULL)
            return 0;
        int l = 100;
        int r = 100;
        if (root->left != NULL)
            l = minDepth(root->left)+1;
        if (root->right != NULL)
            r = minDepth(root->right)+1;
        return l <= r ? l : r;
    }
};

int main(){
    TreeNode t1(5);
    TreeNode t2(3);
    TreeNode t3(4);
    t1.left = &t2;
    t2.right = &t3;
    Solution s;
    cout << s.minDepth(&t1) << endl;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
