/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LowestCommonAncestorOfABinaryTree.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/14 09:02:02
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> tmpret;
        vector<vector<TreeNode *> >ret;

        findNode(root, p, q, tmpret, ret);

        
        for (int i = 0;i < ret.size(); i++){
            for (int j = 0; j < ret[i].size(); j++){
                cout << ret[i][j]->val << " " ;
            }
            cout << endl;
        }

        int i = ret[0].size()-1;
        int j = ret[1].size()-1;
        int k = i < j ? i:j;

        for (; k >=0; k--){
            if (ret[0][k] == ret[1][k])
                return ret[0][k];
        }
        return NULL;
    }

    void findNode(TreeNode* root, TreeNode* p, TreeNode *q, vector<TreeNode *>& tmpret, vector<vector<TreeNode *> >& ret){
        tmpret.push_back(root);
        if (root == p || root == q){
            cout << "HHHHHH" << endl;
            ret.push_back(tmpret);
        }
        if (root->left != NULL){
            findNode(root->left, p, q, tmpret, ret);
            tmpret.pop_back();
        }

        if (root->right != NULL){
            findNode(root->right, p, q, tmpret, ret);
            tmpret.pop_back();
        }
    }
};

int main(){
    TreeNode t1(3);
    TreeNode t2(5);
    TreeNode t3(1);
    TreeNode t4(6);
    TreeNode t5(2);
    TreeNode t6(0);
    TreeNode t7(8);
    Solution s;

    t1.left = &t2;

    cout << s.lowestCommonAncestor(&t1, &t1, &t2)->val << endl;

    

    /*
    t1.left = &t2;
    t1.right = &t3;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    */

    //s.lowestCommonAncestor(&t1, &t2, &t3);
    //cout << (s.lowestCommonAncestor(&t1, &t6, &t7))->val << endl;



}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
