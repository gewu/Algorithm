/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file HouseRobberII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/12 09:34:45
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2){
            return nums[0] > nums[1] ? nums[0]:nums[1];
        }

        int ret1 = getrob(nums, 0, nums.size()-1);
        int ret2 = getrob(nums, 1, nums.size());
       return ret1 > ret2 ? ret1:ret2;
    }

    int getrob(vector<int>& nums, int begin, int end){
        int pre_two = 0;
        int pre_one = nums[begin];
        int ret = 0;

        for (int i = 1+begin; i < end; i++){
            ret = pre_one > pre_two+nums[i]? pre_one:pre_two+nums[i];
            pre_two = pre_one;
            pre_one = ret;
        }

        return ret;
    }
};

int main(){
    int A[] = {1,2,1,0};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    cout << s.rob(nums) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
