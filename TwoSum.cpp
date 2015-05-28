/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file TwoSum.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/28 21:17:37
 * @brief 
 *  
 **/

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ret;
        vector<int> tmp(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size()-1;

        while (i < j){
            if (nums[i]+nums[j] < target)
                i++;
            else if (nums[i]+nums[j] > target)
                j--;
            else if (nums[i]+nums[j] == target){ 
                break;
            }
        }

        int k1 = 0;
        int k2 = nums.size()-1;

        for (;k1 < nums.size(); k1++){
            if (tmp[k1] == nums[i]){
                ++k1;
                break;
            }
        }

        for (; k2 >= 0; k2--){
            if (tmp[k2] == nums[j]){
                ++k2;
                break;
            }
        }
    
        if (k1 > k2){
            ret.push_back(k2);
            ret.push_back(k1);
        }else {
            ret.push_back(k1);
            ret.push_back(k2);
        }
        
        return ret;
    }
};

int main(){
    vector<int> A;
    A.push_back(150);
    A.push_back(24);
    A.push_back(79);
    A.push_back(50);
    A.push_back(88);
    A.push_back(345);
    A.push_back(3);
    int target = 200;
    Solution s;
    vector<int> t = s.twoSum(A, target);
    cout<< t[0] << " " << t[1]<<endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
