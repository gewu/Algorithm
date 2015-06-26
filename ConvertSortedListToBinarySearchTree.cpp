/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ConvertSortedListToBinarySearchTree.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/26 09:31:42
 * @brief 
 *  
 **/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* sortedListToBST(ListNode* head){
        if (head == NULL)
            return NULL;
        if (head->next == NULL){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }

        ListNode *pre = head;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

int main(){

}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
