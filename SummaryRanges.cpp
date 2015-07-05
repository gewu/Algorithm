/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file SummaryRanges.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/07/05 17:30:13
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> ret;
        for (int i=0; i<nums.size(); i++){
            int tmp = nums[i];
            ostringstream out;
            out << tmp;
            int j = i+1;
            for (; j < nums.size(); j++){
                if (nums[j] - tmp != 1){
                    if (j != i+1){
                        out << "->" << tmp;
                    }
                    ret.push_back(out.str());
                    i = j-1;
                    break;
                }
                tmp = nums[j];
            }
            if (j == nums.size()){
                ostringstream tmpout;
                tmpout << nums[j-1];
                if (out.str() != tmpout.str()){
                    out << "->" << nums[j];
                }
                ret.push_back(out.str());
            }
            
        }
        return ret;
    }
};

int main(){
    int A[] = {0,1,2,4,5,7};
    vector<int> nums(&A[0], &A[6]);
    Solution s;
    vector<string> ret = s.summaryRanges(nums);
    for (int i = 0; i<ret.size(); i++){
        cout << ret[i] << " ";
    }
}






















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
