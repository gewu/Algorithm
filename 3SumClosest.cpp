/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file 3SumClosest.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/05 09:53:08
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        int lastindex = nums.size()-2;
        int j = 0;
        int k = 0;
        int diff = abs(nums[0]+nums[1]+nums[2] - target);
        int ret = 0;
        for (int i = 0; i < lastindex; i++){
            j = i+1;
            k = lastindex+1;

            while (j < k){
                int threesum = nums[i]+nums[j]+nums[k];
                int tmpdiff = threesum - target;
                if (tmpdiff == 0)
                    return target;
                if (abs(tmpdiff) <= diff){
                    diff = abs(tmpdiff);
                    ret = threesum;
                }
                tmpdiff < 0 ? ++j:--k;
            }
        }
        return ret;
    }

};

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    Solution s;
    int r = s.threeSumClosest(nums, 0);
    cout << r << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
