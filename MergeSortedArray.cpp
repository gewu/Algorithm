/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MergeSortedArray.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/02 09:33:49
 * @brief 
 *  
 **/

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        if (nums1.size() == 0 || nums2.size() == 0)
            return ;
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
        for (; i >= 0 && j >= 0; k--){
            nums1[k] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        }
        for (; j >= 0; j--){
            nums1[k--] = nums2[j];
        }
    }

};


int main(){
    vector<int> nums1(6);
    vector<int> nums2;

    nums1[0] = 4;
    nums1[1] = 5;
    nums1[2] = 6;

    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    //nums2.push_back(2);
   // nums2.push_back(3);

    for (int i=0; i< nums2.size(); i++){
        cout << nums2[i] << " " ;
    }
    cout<<endl;
    Solution s;
    s.merge(nums1, 3, nums2, 3);

    for (int i=0; i< nums1.size(); i++){
        cout << nums1[i] << " " ;
    }
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
