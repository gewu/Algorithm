/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PowerOfTwo.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/07 09:06:38
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class Solution{
public:
    bool isPowerOfTwo(int n){
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        while (n >= 2){
            if (n % 2 != 0)
                return false;
            n = n/2;
        }
        return true;
    }
};

int main(){
    int n = 1073741825;
    Solution s;
    cout << s.isPowerOfTwo(n) << endl; 
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
