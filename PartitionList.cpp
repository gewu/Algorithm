/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PartitionList.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/03 08:36:24
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
    ListNode* partition(ListNode* head, int x){
        if (head == NULL)
            return head;

        ListNode *key = head;
        ListNode *key_pre = NULL;
        while (key->next != NULL){
            if (key->val >= x)
                break;
            key_pre = key;
            key = key->next;
        }
        if (key == NULL){
            key_pre = NULL;
            key = head;
        }

        ListNode* post = key->next;
        ListNode* pre = key;
        while (post != NULL){
            while ((post != NULL) && (post->val >= x)){
                pre = post;
                post = post->next;
            }

            if (post == NULL)
                return head;
            
            if (pre == key && key->val < x){
                pre = post;
                post = post->next;
                continue;
            }

            pre->next = post->next;
            post->next = key;
            if (key_pre != NULL){
                key_pre->next = post;
                key_pre = post;             //key_pre should go with key;
            }else {
                key_pre = post;
                head = key_pre;
            }
            post = pre->next;
        }

        cout << "hhhhhh" << endl;
        return head; 
    }

};

int main(){
    ListNode t1(1);
    ListNode t2(4);
    ListNode t3(3);
    ListNode t4(2);
    ListNode t5(5);
    ListNode t6(2);

    t1.next = &t2;
    t2.next = &t3;
    t3.next = &t4;
    t4.next = &t5;
    t5.next = &t6;

    Solution s;
    ListNode* head = s.partition(&t1, 3);
    for (; head != NULL; head = head->next){
        cout << head->val << " ";
    }
    cout << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
