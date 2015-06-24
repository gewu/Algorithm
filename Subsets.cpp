/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file Subsets.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/06/24 09:30:51
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> >subsets(vector<int>& nums){
        vector<vector<int> > res;
        vector<int> tmpres;
        res.push_back(tmpres);
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, tmpres, res);
        return res;
    }

    void findSubsets(vector<int>& nums, int start, vector<int> &tmpres, vector<vector<int> >&res){
        for (int i = start; i < nums.size(); i++){
            tmpres.push_back(nums[i]);
            res.push_back(tmpres);
            findSubsets(nums, i+1, tmpres, res);
            tmpres.pop_back();
        }
    }

    vector<vector<int> > subsets2(vector<int> &nums){
        vector<vector<int> > res;
        vector<int> tmpres;
        res.push_back(tmpres);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            int n = res.size();
            for (int j = 0; j < n ; j++){
                tmpres = res[j];
                tmpres.push_back(nums[i]);
                res.push_back(tmpres);
            }

        }
        return res;
    }

};

int main(){

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
