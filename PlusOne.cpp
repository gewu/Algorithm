/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file PlusOne.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/31 14:19:42
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int flag = 0;
        int n = digits.size()-1;
        vector<int> ret(digits.begin(), digits.end());
        for (; n>=0; --n){
            ++ret[n];
            if (ret[n] < 10){
                flag = 1;
                break;
            }
            ret[n] = ret[n] % 10;
        }
        //cout << ret[0] << " " << ret[1] << endl;
        if (digits[0] == ret[0])
            return ret;
        vector<int> ret2;
        ret2.push_back(1);
        for (int i = 0; i < ret.size(); i++){
            ret2.push_back(ret[i]);
        }
        return ret2;
    }        
};

int main(){
    vector<int> nums;
    nums.push_back(9);
    nums.push_back(9);
    Solution s;
    vector<int> v1 = s.plusOne(nums);
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
