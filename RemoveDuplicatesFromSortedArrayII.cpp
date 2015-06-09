/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file RemoveDuplicatesFromSortedArrayII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/09 09:13:44
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if (nums.size() < 1)
            return 0;
        if (nums.size() == 1)
            return 1;

        int sameFlag = 1;
        int index = 0;
        for (int i=1; i<nums.size(); i++){
            if (nums[index] == nums[i]){
                if (sameFlag == 2)
                    continue;
                ++sameFlag;
            }else {
                sameFlag = 1;
            }
            nums[++index] = nums[i];
        }
        return index+1;
    }
};

int main(){
    Solution s;
    int A[] = {1,1,1};
    vector<int> nums(&A[0], &A[3]); 
    cout << s.removeDuplicates(nums) << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
