/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ReverseLinkedList.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/24 11:19:11
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if (head == NULL){
            return NULL;
        }

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = NULL;
        next = cur->next;

        while (cur->next != NULL){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        return cur;
    }
};

int main(){
    ListNode n1(1);
    ListNode n2(2);
    n1.next = &n2;

    Solution s;
    ListNode* h = s.reverseList(&n1);
    while (h->next != NULL){
        cout << h->val<<endl;
        h = h->next;
    }
    cout << h->val;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
