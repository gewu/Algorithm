/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Pow.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/01 21:39:12
 * @brief 
 *  
 **/

#include <iostream>
#include <cstdlib>
using namespace std;

class Solution{
public:
    double myPow(double x, int n);
};

double Solution::myPow(double x, int n){
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        double result = myPow(x, abs(n/2));
        if (n > 0){
            if (n&1) return result*result*x;
            else return result*result;
        }else {
            if (n&1) return 1.0/(result*result*x);
            else return 1.0/(result*result);
        }
}

int main(){
    Solution s;
    cout << s.myPow(5, -1);
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
