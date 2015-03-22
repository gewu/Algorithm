/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreePreorderTraversal.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/20 14:16:59
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
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> value;
        vector<TreeNode *> temp;
        if (root == NULL)
            return value;
        temp.push_back(root);
        TreeNode *pt = root;
        while(!temp.empty()){
            pt = temp.back();
            temp.pop_back();
            value.push_back(pt->val);
            if (pt->right != NULL)
                temp.push_back(pt->right);
            if (pt->left != NULL)
                temp.push_back(pt->left);
        }
        return value;
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;
    Solution solution;
    vector<int> temp = solution.preorderTraversal(&t1);
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << " " ;

}





/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
