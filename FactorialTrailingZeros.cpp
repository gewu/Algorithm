/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FactorialTrailingZeros.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/23 20:57:04
 * @brief 
 *  
 **/

class Solution {
public:
    int trailingZeroes(int n){
        int count_five = 0;
        while (n > 0){
            int k = n/5;
            count_five += k;
            n = k;
        }
        return count_five;    
    }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
