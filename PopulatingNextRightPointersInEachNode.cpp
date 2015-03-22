/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PopulatingNextRightPointersInEachNode.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/20 15:29:47
 * @brief 
 *  
 **/

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution{
public:
    void connect(TreeLinkNode *root){
        connect(root, NULL);
    }
private:
    void connect(TreeLinkNode *root, TreeLinkNode *sibling){
        if (root == NULL)
            return;
        else 
            root->next = sibling;
        connect(root->left, root->right);
        if (sibling)
            connect(root->right, sibling->left);
        else 
            connect(root->right, NULL);
    }
};




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
