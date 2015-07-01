/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file RemoveLinkedListElements.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/30 08:21:36
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        while (head != NULL && head->val == val){
            head = head->next;
        }
        if (head == NULL){
            return NULL;
        }

        ListNode *pre = head;
        ListNode* cur = pre->next;
        while (cur != NULL){
            if (cur->val == val){
                pre->next = cur->next;
            }else{
                pre = pre->next;
            }
            cur = cur->next;
        }
        return head;
    }
};
int main(){
    ListNode t1(1);
    //ListNode t2(2);
    //ListNode t3(3);
    //t1.next = &t2;
    //t2.next = &t3;

    Solution s;
    ListNode *h = s.removeElements(&t1, 1);
    while (h != NULL){
        cout << h->val << " ";
        h = h->next;
    }
        
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
