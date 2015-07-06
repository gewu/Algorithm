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
        int maj_index = 0;
        int count = 1;
        for (int i = 1; i < num.size(); i++){
            if (num[maj_index] == num[i])
                ++count;
            else 
                --count;
            if (count < 0){
                maj_index = i;
                count = 1;
            }
        }
        return num[maj_index];
    }
};

int main(){
    int A[] = {1,2,1,2,1,2,3,3};
    vector<int> num(&A[0], &A[7]);

    Solution solution;
    int val = solution.majorityElement(num);
    cout << val << endl;
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
