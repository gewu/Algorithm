/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreeInorderTraversal.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/20 16:23:44
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
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        const TreeNode *p = root;
        vector<TreeNode *> s;
        while (!s.empty() || p != NULL){
            if (p != NULL){
                s.push_back(p);
                p = p->left;
            }else {
                p = s.back();
                s.pop_back();
                p = p->right;
            }
        }
        return result;
    }
};

int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;
    Solution solution;
    solution.inorderTraversal(&t1);
    //for (int i = 0; i < temp.size(); i++){
    //    cout << temp[i] << " ";
   // }
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
