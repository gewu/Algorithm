/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file LinkedListCycleII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/24 17:01:20
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

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                slow = head;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

int main(){
    ListNode n1(1);
    ListNode n2(2);

    n1.next = &n2;
    Solution s;
    
    ListNode *p = s.detectCycle(&n1);
    if (p == NULL)
        cout << "Why";
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
