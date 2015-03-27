/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SwapNodesInPairs.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/26 20:56:15
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

class Solution{
public:
    ListNode *swapPairs(ListNode *head){
        if (head == NULL)
            return head;
        ListNode root(0);
        root.next = head;
        ListNode *pre = &root;
        ListNode *cur = root.next;
        ListNode *nex = NULL;
        while(cur != NULL && cur->next != NULL){
            nex = cur->next;
            pre->next = nex;
            cur->next = nex->next;
            nex->next = cur;

            pre = cur;
            cur = cur->next;
        }
        return root.next;        
    }
};

int main(){
    ListNode val1(1);
    ListNode val2(2);
    ListNode val3(3);
    ListNode val4(4);

    val1.next = &val2;
    val2.next = &val3;
    val3.next = &val4;

    Solution solution;
    ListNode *pln = solution.swapPairs(&val1);
   while (pln != NULL){
        cout << pln->val;
        pln = pln -> next;
    }
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
