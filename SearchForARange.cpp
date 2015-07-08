/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SearchForARange.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/08 08:41:36
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        if (low > high){
            return vector<int>(2, -1);
        }
        int mid = (low+high)/2;

        while (low <= high){
            if (nums[mid] < target){
                low = mid+1;
            }else if (nums[mid] > target){
                high = mid-1;
            }else {
                return find(nums, mid);
            }

            mid = (low+high)/2;
        }

        return vector<int>(2,-1);
    }
    
    vector<int> find(vector<int>& nums, int i){
        //cout << i << endl;
        vector<int> ret(2, i);
        int l = i;
        int h = i;
        while (l > 0 && nums[--l] == nums[i]){
            ret[0] = l;
        }
        if (nums[ret[0]] != nums[i]){
            ret[0] = i;
        }
        
        cout << "i " << i << endl;
        while (h < nums.size()-1 && nums[++h] == nums[i]){
            ret[1] = h;
        }
        cout << nums[ret[1]] << endl;
        cout << ret[1] << endl;
        if (nums[ret[1]] != nums[i]){
            ret[1] = i;
        }

        
        return ret;
    }
};

int main(){
    //int A[] = {5,7,7,8,8,10};
    int A[] = {1,1,2};
    vector<int> nums(&A[0], &A[3]);
    Solution s;
    vector<int> ret = s.searchRange(nums, 1);
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << " " ;
    
    cout << endl;
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
