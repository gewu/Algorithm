/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file JumpGame.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/16 16:09:33
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        int last_index = nums.size()-1;

        for (int i = nums.size()-2; i>=1; i--){
            if (nums[i] >= last_index-i)
                last_index = i;
        }

        return nums[0] >= last_index ? true:false;
    }
};

int main(){
    int A[] = {3,2,1,0,4};
    vector<int> nums(&A[0], &A[5]);
    Solution s;
    cout << s.canJump(nums) << endl;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
