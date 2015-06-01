/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FindMinimumInRotatedSortedArray.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/24 19:07:55
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findMin(vector<int> &num){
        int low = 0;
        int high = num.size()-1;
        int value = num[0];
        while (low <= high){
            int mid = (low+high)/2;
            if (num[mid] <= num[high])
                high = mid - 1;
            else 
                low = mid + 1;
            value = value < num[mid] ? value:num[mid];
        }
        return value;
    }
};

int main(){
    vector<int> num;
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(0);
    num.push_back(1);
    num.push_back(2);

    Solution solution;
    int val = solution.findMin(num);
    cout << val;
}

int main(){
    int A = {4,5,6,7,0,1,2};
    vector<int> nums(&A[0], &A[7]);
    Solution s ;
    s.findMin(nums);
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
