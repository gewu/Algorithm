/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SubsetsII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/01 08:39:10
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums){
        vector<int> tmpret;
        vector<vector<int> > ret;
        ret.push_back(tmpret);
        sort(nums.begin(), nums.end());

        int start = 0;
        for (int i = 0; i < nums.size(); i++){
            int size = ret.size();
            for (int j = start; j < size; j++){
                tmpret = ret[j];
                tmpret.push_back(nums[i]);
                ret.push_back(tmpret);
            }

            if (i < nums.size()-1 && nums[i] == nums[i+1]){
                start = size;
            }else {
                start = 0;
            }
        }
        return ret;
    }
};


int main(){
    //int A[] = {5,5,5,5};
    int A[] = {5,5,5,5};
    vector<int> nums(&A[0], &A[4]);
    Solution s;
    vector<vector<int> > ret = s.subsetsWithDup(nums);    
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << " " ;
        }
        cout << endl;
    }
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
