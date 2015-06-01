/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FindMinimumInRotatedSortedArrayII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/31 10:15:31
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums){
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() < 0)
            return -1;
        int low = 0;
        int high = nums.size()-1;
        int mid = (low + high)/2;
        int min = nums[0];

        while (low < high){
            if (nums[mid] > nums[low]){
                min = min < nums[low] ? min: nums[low];
                low = mid+1;
            }else if (nums[mid] < nums[low]){
                min = min < nums[mid]? min: nums[mid];
                high = mid-1;
            }else {
                min = min < nums[low]? min: nums[low];
                ++low;
            }
            mid = (low+high)/2;
        }
        
        min = min < nums[low] ? min: nums[low];
        min = min < nums[high]? min: nums[high];
        return min;
    }
};

int main(){
    int A[] = {2,3,0,2};
    vector<int> nums(&A[0], &A[7]);
    Solution s;
    cout<< s.findMin(nums);
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
