/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinaryTreePostTraversal.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/27 09:48:27
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution{
public:
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> path;
        stack< pair<TreeNode *, bool> >s;
        s.push(make_pair(root, false));
        bool visited;
        while(!s.empty()){
            root = s.top().first;
            visited = s.top().second;
            s.pop;
            if (root == NULL)
                continue;
            if (visited){
                path.push_back(root->val);
            }else {
                s.push(make_pair(root, true));
                s.push(make_pair(root->right, false));
                s.push(make_pair(root->left, false));
            }
        }
        return path;
    }

    void postorderTraversal(TreeNode *root){
        if (root == NULL)
            return ;
        if (root->left != NULL)
            postorderTraversal(root->left);
        if (root->right != NULL)
            postorderTraversal(root->right);
        cout << root->val << endl;
    }
};


int main(){
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);

    t1.right = &t2;
    t2.left = &t3;
    Solution solution;
    solution.postorderTraversal(&t1);
}















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
