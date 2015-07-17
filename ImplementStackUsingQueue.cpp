/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ImplementStackUsingQueue.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/17 11:22:50
 * @brief 
 *  
 **/

#include <iostream>
#include <queue>
using namespace std;

class Stack{
public:
    queue<int> q1, q2, temp;
    
    void push(int x){
        q1.push(x);
    }

    void pop(){
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        temp = q2;
        q2 = q1;
        q1 = temp;
    }
    
    int top(){
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        return q1.front();
    }

    bool empty(){
        return q1.empty()&&q2.empty();
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;     
    cout << s.top() << endl;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
