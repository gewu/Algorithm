/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ImplementQueueUsingStacks.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/16 10:12:00
 * @brief 
 *  
 **/

#include <stack>
#include <iostream>
using namespace std;

class Queue{
public:
    void push(int x){
        st1.push(x);
    }

    void pop(void){
        if (st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        st2.pop();
    }

    int peek(void){
        if (st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty(void){
        return st1.empty() && st2.empty();
    }

    stack<int> st1;
    stack<int> st2;
};

int main(){
    Queue q;
    q.push(5);
    q.push(6);
    cout << q.peek() << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
