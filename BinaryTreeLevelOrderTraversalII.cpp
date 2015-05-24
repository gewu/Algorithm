/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreeLevelOrderTraversalII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/24 12:05:40
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
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root){
        vector<vector<int> > ret;
        vector<int> num;
        
        if (root == NULL){
            return ret;
        }

        queue<TreeNode *> s;
        s.push(root);
        s.push(NULL)
        TreeNode *p = NULL;
        while(!s.empty()){
            p = s.front();
            s.pop();

            if (p != NULL){
                num.push_back(p->val);
                if (p->left != NULL)
                    s.push(p->left);
                if (p->right != NULL)
                    s.push(p->right);
            }else {
                ret.push_back(num);
                num.clear();

                if (!s.empty()){
                    s.push(NULL);                    
                }
            }
        } 

        vector<vector<int> > result;
        vector<vector<int> >::iterator it = ret.end();
        while(it != ret.begin())
            result.push_back(*(--it));
        return result;
    } 

};


int main(){
    TreeNode r1(3);
    TreeNode r2(9);
    TreeNode r3(20);
    TreeNode r4(15);
    TreeNode r5(7);

    r1.left = &r2;
    r1.right = &r3;
    r3.left = &r4;
    r3.right = &r5;

    Solution s;
    vector<vector<int> > v1;
    v1 = s.levelOrderBottom(&r1);
    cout << v1[0][1];
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
