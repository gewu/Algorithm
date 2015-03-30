/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file FindPeakElement.cpp
 * @author gewu(com@baidu.com)
 * @date 2015/03/30 09:35:57
 * @brief 
 *  
 **/

class Solution{
public:
    int findPeakElement(const vector<int> &num){
        int left = 0;
        int right = num.size()-1;
        while (left <= right){
            if (left == right)
                return left;
            int mid = (left+rigth)/2;
            if (num[mid] < num[mid+1])
                left = mid+1;
            else 
                right = mid;
        }
    }
};





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
