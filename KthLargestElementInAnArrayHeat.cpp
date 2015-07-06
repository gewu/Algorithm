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
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size()/2;
        for (; n>=0; n--){
            sink(nums, n, nums.size()-1);
        }
        
        int N = nums.size()-1;
        for (int j = k; j > 1; j--){
            swap(nums, 0, N--);
            sink(nums, 0, N);
        }
        return nums[0];

    }

    void swap(vector<int>& A, int i, int j){
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    void sink(vector<int>& A, int k, int N){
        if (N == 0)
            return ;
        while (2*k <= N){
            int j = 2*k;
            if (k == 0)
                j = 1;
            if (j < N && A[j+1] > A[j]){
                ++j;
            }
            if (A[k] > A[j])
                break;
            swap(A, k, j);
            k = j;
        }
    }
};

int main(){
    int A[] = {2,1};
    vector<int> nums(&A[0], &A[2]);
    Solution s;
    cout << s.findKthLargest2(nums, 2) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
