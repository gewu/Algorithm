/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file IntersectionOfTwoLinkedLists.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/25 09:17:00
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *A = headA;
        ListNode *B = headB;
        
        int aLen = 0;
        int bLen = 0;
        for (; A != NULL; A = A->next){
            ++aLen;
        }

        for (; B != NULL; B = B->next){
            ++bLen;
        }

        A= headA;
        B = headB;
        if (aLen > bLen){
            int c = aLen - bLen;
            for (; c!=0; c--){
                A = A->next;
            }
        }else if (aLen < bLen){
            int c = bLen - aLen;
            for (; c!=0; c--){
                B = B->next;
            }
        }

        while (A != NULL){
            if (A == B)
                return A;
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
};

int main(){

    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    ListNode t4(4);
    ListNode t5(5);
    ListNode t6(6);
    /*
    t1.next = &t2;
    t2.next = &t5;
    t5.next = &t6;
    t3.next = &t4;
    t4.next = &t5;
    */

    Solution s;
    if (s.getIntersectionNode(NULL, &t1) == NULL)
        cout << "YES" << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
