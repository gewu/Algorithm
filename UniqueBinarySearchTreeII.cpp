/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file UniqueBinarySearchTreeII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/10 09:28:35
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n){
        return genBST(1,n);
    }

    vector<TreeNode *> genBST(int min, int max){
        vector<TreeNode *> ret;
        if (min > max){
            ret.push_back(NULL);
            return ret;
        }

        for (int i = min; i <= max; i++){
            vector<TreeNode*> leftSubTree = genBST(min, i-1);
            vector<TreeNode*> rightSubTree = genBST(i+1, max);
            for (int j = 0; j <leftSubTree.size(); j++){
                for (int k = 0; k<rightSubTree.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    ret.push_back(root);   
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
