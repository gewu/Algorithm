/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file BestTimeToBuyAndSellStock.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/19 09:46:20
 * @brief 
 *  
 **/

#include <iostream>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int sum = 0;
        for (int i = 1; i < prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            if (diff > 0)
                sum += diff;
        }       
       return sum; 
    }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
