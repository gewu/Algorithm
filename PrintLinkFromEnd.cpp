/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PrintLinkFromEnd.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/12 20:56:43
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

void printfromend(ListNode* p){
    if (p == NULL)
        return ;
    if (p != NULL)
        printfromend(p->m_pNext);
    cout << p->m_nKey<<" ";
}

int main(){
    ListNode l1;
    ListNode l2;
    ListNode l3;
    l1.m_nKey = 1;
    l1.m_pNext = &l2;
    l2.m_nKey = 2;
    l2.m_pNext = &l3;
    l3.m_nKey = 3;
    l3.m_pNext = NULL;
    
    printfromend(&l1);

}

























/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
