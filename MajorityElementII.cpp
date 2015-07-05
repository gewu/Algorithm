/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file MajorityElementII.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/05 15:24:24
 * @brief 
 *  
 **/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> majorityElement(vector<int> &nums){
        vector<int> ret;
        if (nums.size() == 0)
            return ret;
        int m = nums[0];
        int n = 0;
        for (int tmp = 1; tmp != nums.size(); tmp++){
            if (nums[tmp] != m){
                n = nums[tmp];
                break;
            }
        }

        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == m){
                ++c1;
            }else if(nums[i] == n) {
                ++c2;
            }else if (c1 == 0) {
                m = nums[i];
                c1 = 1;
            }else if (c2 == 0){
                n = nums[i];
                c2 = 1;
            }else {
                --c1;
                --c2;
            }
        }
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < nums.size(); i++){
            if (m == nums[i])
                c1++;
            else if (n == nums[i])
                c2++;
        }
        if (c1 > nums.size()/3)
            ret.push_back(m);
        if (c2 > nums.size()/3 && m != n)
            ret.push_back(n);
        return ret;
    }
};

int main(){
    Solution s;
    int A[] = {4,2,1,1};
    vector<int> nums(&A[0], &A[4]);
    vector<int> ret = s.majorityElement(nums);
    for (int i = 0 ; i < ret.size(); i++){
        cout << ret[i] << " " << endl;
    }
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
