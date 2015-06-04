/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SumRootToLeafNumbers.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/03 21:51:39
 * @brief 
 *  
 **/

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    int sumNumbers(TreeNode* root){
        return Sum(root, 0);

    }

    void Sum(TreeNode* root, int sum){
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return sum*10+root->val;
        else 
            return Sum(root->left, sum*10+root->val)+Sum(root->right, sum*10+root->val);
    }

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
