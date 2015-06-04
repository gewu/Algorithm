/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file ContainsDuplicateII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/05/31 18:41:09
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k){
        map<int, vector<int> >ret;
        for (int i = 0; i < nums.size(); i++){
            if (ret.find(nums[i]) == ret.end()){
                vector<int> tmp(1, i);
                ret.insert(pair<int, vector<int> >(nums[i], tmp));
            }else {
                ret[nums[i]].push_back(i);
            }
        }

        map<int, vector<int> >::iterator it = ret.begin();
        for (; it != ret.end(); it++){
            if ((it->second).size() > 1){
                int min = it->second[1]-it->second[0];
                for (int j = 0; j+1 < it->second.size(); j++){
                    int num_tmp = it->second[j+1] - it->second[j];
                    if (min > num_tmp)
                        min = num_tmp;
                }
                if (min <= k)
                    return true;
            }
        }
        return false;
    }
};


int main(){
    int A[] = {1,0,1,1};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    cout << s.containsNearbyDuplicate(nums, 1)<< endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
