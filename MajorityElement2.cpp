/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/ 
/**
 * @file MajorityElement2.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/21 16:39:59
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int> &num){
        vector<int>::iterator iter1 = num.begin();
        vector<int>::iterator iter2 = num.begin() + 1; 
        for (; iter1 != num.end() && iter2 != num.end();){
            if (*iter1 != *iter2){
                num.erase(iter1);
                iter2 = num.erase(iter2);
                iter1 = iter2;
                ++iter2;
            } else {
                iter1 ++;
                iter2 ++;
            }
        }
        return 0;
    }
};

int main(){
    vector<int> num;
    num.push_back(10);
    num.push_back(9);
    num.push_back(9);
    num.push_back(9);
    num.push_back(8);
    Solution solution;
    int val = solution.majorityElement(num);
    cout << val << endl;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
