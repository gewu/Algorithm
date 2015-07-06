/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file KthLargestElementInAnArray.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/06 08:41:15
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findKthLargest2(vector<int>& nums, int k){
        return findK(nums, k, 0, nums.size()-1);
    }

    int findK(vector<int>& nums, int k, int i, int j){
        if (i >= j)
            return nums[i];
        int m = partition(nums, i, j);
        if (m == k)
            return nums[m];
        else if (m < k){
            return findK(nums, k, m+1, j);
        }else {
            return findK(nums, k, i, m-1);
        }
    }

    int partition(vector<int>& A, int low, int high){
        int i = low;
        int j = high+1;
        int key = A[low];

        while(1){
            while(A[++i] > key){
                if (i == high)
                    break;
            }
            while (A[--j] < key){
                if (j == low)
                    break;
            }
            if (i >= j)
                break;
            swap(A, i, j);
        }
        swap(A, j, low);
        return j;
    }

};

int main(){
    int A[] = {2,1};
    vector<int> nums(&A[0], &A[2]);
    Solution s;
    cout << s.findKthLargest2(nums, 2) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
