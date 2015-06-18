/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BinarySearchTreeIterator.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/18 09:48:30
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class BSTIterator{
public:
    BSTIterator(TreeNode *root){
        index = 0;
        TreeNode *p = root;
        stack<TreeNode *> s;
        while (!s.empty()||p != NULL){
            if (p != NULL){
                s.push(p);
                p = p->left;
            }else {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
    }

    bool hasNext() {
        return index < result.size()? 1 : 0;
    }

    int next(){
        return result[index++];
        
    }
private:
    vector<int> result;
    int index;
};


int main(){
    TreeNode t1(1);
    TreeNode t2(3);
    TreeNode t3(6);
    //t1.left = &t2;
    t1.right = &t3;

    BSTIterator s(&t1);
    while (s.hasNext())
        cout << s.next() << " ";

}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
