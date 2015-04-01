/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PathSum.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/04/01 08:47:11
 * @brief 
 *  
 **/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNOde(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool hasPathSum1(TreeNode *root, int sum){
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && root->val == sum)
            return true;
        return hasPathSum1(root->left, sum-root->val) || hasPathSum1(root->right, sum-root->val);
    }

    vector<vector<int> > pathsum(TreeNode *root, int sum){
        vector<int> path;
        vector<vector<int> > paths;
        if (root == NULL){
            return paths;
        }
        pathSum(root, sum. path, paths);
        return paths;
    }
    void pathSum(TreeNode *root, int sum, vector<int>& path, vector<vector<int> >& paths){
        path.push_back(root->val);
        int cur = sum - root->val;

        if (root->left == NULL && root->right == NULL && cur == 0)
            paths.push_back(path);
        if (root->left != NULL){
            pathSum(root->left, cur, path, paths);
            path.pop_back();
        }
        if (root->right != NULL){
            pathSum(root->right, cur, path, paths);
            path.pop_back();
        }

    }
};


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
