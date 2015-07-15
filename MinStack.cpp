/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MinStack.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/15 16:51:51
 * @brief 
 *  
 **/

#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
    void push(int x){
        if (s.empty() || min.top() >= x){
            min.push(x);
        }
        s.push(x);
    }

    void pop(){
        if (s.top() == min.top()){
            min.pop();
        }
        s.pop();
    }

    int top(){
        return s.top();
    }
    int getMin(){
        return min.top();
    }

private:
    stack<int> s;
    stack<int> min;
};

int main(){
    MinStack sta;
    sta.push(-2);
    sta.push(0);
    sta.push(-1);

    cout << sta.getMin() << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
