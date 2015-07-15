/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file NumberOfDigitOne.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/15 09:21:06
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class Solution{
public:
    int countDigitOne(int n){
        long long ans = 0, base = 1, last = 0;
        while (n){
            int t = n%10;
            n /= 10;
            if (t > 1)
                ans += (n+1)*base;
            else if (t == 1)
                ans += n*base+last+1;
            else
                ans += n*base;
            last = t*base+last;
            base *= 10;
        }
        return ans;
    }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
