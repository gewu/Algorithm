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
#include <vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices){
        int low = prices[0];
        int max = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            profit = prices[i] - low;
            if (profit > max)
                max = profit;
            if (low > prices[i])
                low = prices[i];
        }
        return max;        
    }
};

int main(){
    vector<int> A ;
    A.push_back(2);
    A.push_back(1);
    A.push_back(4);
    A.push_back(5);
    A.push_back(0);
    A.push_back(9);
    Solution solution;
    int val = solution.maxProfit(A);
    cout << val << endl;

}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
