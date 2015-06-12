/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file HouseRobber.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/12 09:10:42
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
        int dp[nums.size()];
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++){
            dp[i] = dp[i-1] > (dp[i-2]+nums[i-1]) ? dp[i-1] : (dp[i-2]+nums[i-1]);
        } 

        return dp[nums.size()];
    }

    int rob2(vector<int>& nums){
        if (nums.size() == 0)
            return 0;
        int preOne = nums[0];
        int preTwo = 0;
        int ret = nums[0];
        for (int i = 2; i <= nums.size(); i++){
            ret = preOne > preTwo+nums[i-1]? preOne : (preTwo+nums[i-1]);
            preTwo = preOne;
            preOne = ret;
        }
        return ret;
    }
};

int main(){
    int A[] = {2,1,1,2};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    cout << s.rob2(nums) << endl;
}












 








/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
