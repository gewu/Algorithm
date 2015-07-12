/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PalindromeLinkedList.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/12 10:30:06
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
    bool isPalindrome(ListNode* head){
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* s = head;
        ListNode* f = head;
        while (f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
        }

        ListNode* flag = s;
        if (f != NULL && f->next == NULL){
            s = s->next;
        }

        f = reverse(s);
        cout << f->val << endl;
        ListNode *f2 = head;
        
        while (f != NULL){
            if (f->val != f2->val)
                return false;
            f = f->next;
            f2 = f2->next;
        }
        if (f2 == flag)
            return true;
        return false;
    }

    ListNode *reverse(ListNode *p){
        if (p == NULL || p->next == NULL)
            return p;
        ListNode *pre = NULL;
        ListNode *cur = p;
        ListNode *next = p->next;

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
    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    /*ListNode *p5 = new ListNode(1);
    */
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    /*p4->next = p5;
    */

    Solution s;
    
    cout << s.isPalindrome(p1) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
